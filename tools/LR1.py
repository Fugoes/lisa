#!/usr/bin/env python3
from collections import defaultdict
from jinja2 import Template


class Grammar(object):
    def __init__(self, content):
        assert isinstance(content, str)
        self.content = content
        # terminals, non-terminals, rules as dict from non-terminals to list of right hand side of production rules
        self.Ts, self.Ns, self.rules = self.get_Ts_Ns_rules()
        # FIRST() of all terminals and non-terminals
        self.FIRST = self.get_FIRST()
        # rule strings (e.g. 'A : B C')
        self.rule_str = self.get_rule_str()
        # rule string to rule index
        self.rule_str_to_index = self.get_rule_str_to_index()
        # get go table
        self.go = self.get_go("Root : . Start, EOFF")
        # get actions table (state -> terminal -> r<index of rule> | s<state to push>)
        # and gotos table (state -> non-terminal -> <state to push>)
        self.actions, self.gotos = self.get_actions_gotos()

    @staticmethod
    def is_T(token):
        return token.upper() == token

    @staticmethod
    def split_to_P(s):
        A, rs = s.split(":")
        A = A.strip()
        rs = rs.strip()
        a, t = [x.strip() for x in rs.split(",")]
        alpha, beta = [x for x in a.split(".")]
        alpha = [x for x in alpha.split(" ") if len(x) > 0]
        beta = [x for x in beta.split(" ") if len(x) > 0]
        return A, alpha, beta, t

    @staticmethod
    def move_P(s):
        A, alpha, beta, t = Grammar.split_to_P(s)
        if len(beta) == 0:
            return False, t, "%s : %s" % (A, " ".join(alpha))
        else:
            alpha, beta = alpha + [beta[0]], beta[1:]
            return True, alpha[-1], "%s : %s %s, %s" % (A, " ".join(alpha), " ".join(["."] + beta), t)

    def get_rule_str(self):
        rule_str = []
        for A, RHSs in self.rules.items():
            for RHS in RHSs:
                rule_str.append("%s : %s" % (A, " ".join(RHS)))
        rule_str.sort()
        return rule_str

    def get_rule_str_to_index(self):
        rule_str_to_index = dict()
        for index, rule_str in enumerate(self.rule_str):
            rule_str_to_index[rule_str] = index
        return rule_str_to_index

    def get_Ts_Ns_rules(self):
        Ts = {"EOFF"}
        Ns = set()
        rules = defaultdict(lambda: [])
        for line in self.content.splitlines():
            if len(line) == 0:
                continue
            tokens = [token for token in line.split(' ') if len(token) > 0 and token != "E"]
            if tokens[0] == "//":
                continue
            if tokens[0] != '|':
                key = tokens[0]
                assert tokens[1] == ':'
                tokens = tokens[2:]
            else:
                tokens = tokens[1:]
            rules[key].append(tokens)
            if Grammar.is_T(key):
                Ts.add(key)
            else:
                Ns.add(key)
            for token in tokens:
                if Grammar.is_T(token):
                    Ts.add(token)
                else:
                    Ns.add(token)
        return Ts, Ns, rules

    def get_FIRST(self):
        FIRST = defaultdict(lambda: set())
        FIRST["E"].add("E")
        for T in self.Ts:
            FIRST[T] = {T}
        while True:
            changed = False
            for A, gammas in self.rules.items():
                num = len(FIRST[A])
                for gamma in gammas:  # A -> gamma
                    flag = True
                    if len(gamma) == 0:
                        FIRST[A].add("E")
                        continue
                    for Y in gamma:
                        FIRST[A] = FIRST[A].union(FIRST[Y] - {"E"})
                        if "E" not in FIRST[Y]:
                            flag = False
                            break
                    if flag:
                        FIRST[A].add("E")
                if len(FIRST[A]) > num:
                    changed = True
            if not changed:
                return FIRST

    def get_first(self, tokens):
        assert isinstance(tokens, list)
        r = set()
        for token in tokens:
            if "E" not in self.FIRST[token]:
                r = r.union(self.FIRST[token])
                return r
            else:
                r = r.union(self.FIRST[token] - {"E"})
        r.add("E")
        return r

    def get_CLOSURE(self, ts):
        ts = set([t for t in ts.split('\n') if len(t) > 0])
        while True:
            rs = set()
            for A, alpha, beta, t in map(Grammar.split_to_P, ts):  # A -> alpha . beta, cs
                if len(beta) > 0:
                    B, beta = beta[0], beta[1:]  # A -> alpha . B beta, t
                    if B in self.Ns:
                        for gamma in self.rules[B]:  # B -> gamma
                            for token in self.get_first(beta + [t]):
                                new_s = "%s : . %s, %s" % (B, " ".join(gamma), token)
                                if new_s not in ts:
                                    rs.add(new_s)
            if len(rs) > 0:
                ts = ts.union(rs)
            else:
                ts = list(ts)
                ts.sort()
                return "\n".join(ts)

    def get_go(self, root):
        Is = dict()
        Is[self.get_CLOSURE(root)] = len(Is)
        go = defaultdict(lambda: defaultdict(lambda: None))
        while True:
            changed = False
            for I in list(Is.keys())[:]:
                n = Is[I]
                d = defaultdict(lambda: [])
                for P in I.split('\n'):
                    flag, t, new_P = Grammar.move_P(P)
                    if flag:  # could move
                        d[t].append(new_P)
                    else:
                        assert go[n][t] is None or go[n][t] == new_P
                        go[n][t] = new_P
                for t, new_I in d.items():
                    new_I = "\n".join(new_I)
                    new_I = self.get_CLOSURE(new_I)
                    if new_I not in Is:
                        Is[new_I] = len(Is)
                        changed = True
                    assert go[n][t] is None or go[n][t] == Is[new_I]
                    go[n][t] = Is[new_I]
            if not changed:
                return go

    def get_actions_gotos(self):
        actions = defaultdict(lambda: defaultdict(lambda: None))
        gotos = defaultdict(lambda: defaultdict(lambda: None))
        for n, x in self.go.items():
            for t, m in x.items():  # GO[n, t] = m
                if t in self.Ts:
                    if isinstance(m, int):
                        actions[n][t] = "s%d" % m
                    else:
                        actions[n][t] = "r%d" % self.rule_str_to_index[m]
                else:
                    gotos[n][t] = m
        return actions, gotos

    def gen_code(self):
        # get variables passed to templates
        # variables for terminals and non-terminals
        g = dict()
        g["Ts"] = list(self.Ts)
        g["Ts"].sort()
        g["Ns"] = list(self.Ns)
        g["Ns"].sort()
        g["rule_str"] = self.rule_str
        # variables for switch statements in parse() function
        parse = defaultdict(lambda: defaultdict(lambda: defaultdict(lambda: set())))
        for state, xs in self.actions.items():
            for T, action in xs.items():
                if action[0] == "s":  # shift
                    is_shift = True
                    state_to_push = int(action[1:])
                    parse[state][is_shift][state_to_push].add(T)
                else:  # reduce
                    is_shift = False
                    index_of_rule = int(action[1:])
                    parse[state][is_shift][index_of_rule].add(T)
        g["parse"] = []
        for state, xs in parse.items():
            lines = []
            # is_case, is_shift, is_reduce
            g["parse"].append((state, lines))
            for is_shift, ys in xs.items():
                for num, Ts in ys.items():
                    Ts = list(Ts)
                    Ts.sort()
                    for T in Ts:
                        lines.append((True, False, False, T, None))
                    if is_shift:
                        assert len(Ts) == 1
                        lines.append((False, True, False, Ts[0], num))
                    else:
                        lines.append((False, False, True, num, None))
        g["parse"].sort()
        goto = defaultdict(lambda: defaultdict(lambda: set()))
        for state, xs in self.gotos.items():
            for T, state_to_push in xs.items():
                goto[state][state_to_push].add(T)
        g["goto"] = []
        for state, xs in goto.items():
            l = []
            g["goto"].append((state, l))
            for state_to_push, Ts in xs.items():
                Ts = list(Ts)
                Ts.sort()
                l.append((Ts, state_to_push))
        g["goto"].sort()
        # get number of node needed to pop when reducing
        g["pop_num"] = [len([None for T in rule.split(':')[1].split(' ') if len(T) > 0]) for rule in self.rule_str]
        g["as"] = [rule.split(':')[0].strip() for rule in self.rule_str]
        # render template
        with open("LNodeType.h", "w") as f:
            t = Template(lnodetype_h_template)
            f.write(t.render(g=g))
        with open("LParser.h", "w") as f:
            t = Template(lparser_h_template)
            f.write(t.render(g=g))
        with open("LParser.cpp", "w") as f:
            t = Template(lparser_cpp_template)
            f.write(t.render(g=g))


lnodetype_h_template = """#ifndef LISA_LTOKENTYPE_H
#define LISA_LTOKENTYPE_H

enum class LNodeType {
    INVALID{% for T in g["Ts"] %},
    {{ T }}{% endfor %}{% for N in g["Ns"] %},
    {{ N }}{% endfor %}
};

#endif
"""

lparser_cpp_template = """#include "LParser.h"

{% for rule_str in g["rule_str"] %}
std::optional<std::shared_ptr<LNode>> LParser::reduce_{{ loop.index - 1 }}() {
    // {{ rule_str }}
    return std::make_shared<LNode>();
}
{% endfor %}{% for T in g["Ts"] %}
std::optional<std::shared_ptr<LNode>> LParser::shift_{{ T }}() {
    this->move();
    return std::make_shared<LNode>();
}
{% endfor %}
"""

lparser_h_template = """#ifndef LISA_LPARSER_H
#define LISA_LPARSER_H

#include "LLexer.h"
#include "LNode.h"

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>

class LParser {
public:
    std::unique_ptr<LLexer> lexer;

    LToken peek;

    std::vector<int> state_stack;

    std::vector<std::shared_ptr<LNode>> node_stack;

    bool terminated{false};

    void error() {
        std::cout << "ERROR" << std::endl;
        this->terminated = true;
    }

    void accept() {
        std::cout << "ACCEPT" << std::endl;
        this->terminated = true;
    }

    void move() {
        this->peek = this->lexer->next_token().value();
        std::cout << this->peek.str() << std::endl;
    }

    void pop(int n) {
        for (int i = 0; i < n; i++) {
            this->state_stack.pop_back();
            this->node_stack.pop_back();
        }
    }

    void push(int state, const std::shared_ptr<LNode> &node) {
        this->state_stack.push_back(state);
        this->node_stack.push_back(node);
    }

    int GOTO(int state, LNodeType node_type) {
        switch (state) {
            {% for state, xs in g["goto"] %}case {{ state }}:
                switch (node_type) {
                    {% for Ts, state_to_push in xs %}{% for T in Ts %}case LNodeType::{{ T }}:
                        {% endfor %}return {{ state_to_push }};
                    {% endfor %}default:
                        return -1;
                }
            {% endfor %}default:
                return -1;
        }
    }

    int top_state() {
        return this->state_stack[this->node_stack.size() - 1];
    }

    void parse() {
        this->push(0, nullptr);
        std::optional<std::shared_ptr<LNode>> r;
        int flag = -1;
        while (!this->terminated) {
            switch (this->top_state()) {
                {% for state, lines in g["parse"] %}case {{ state }}:
                    switch (this->peek.type) {% raw %}{{% endraw %}{% for is_case, is_shift, is_reduce, a, b in lines %}
                        {% if is_case %}case LNodeType::{{ a }}:{% elif is_shift %}    r = this->shift_{{ a }}();
                            if (!r.has_value()) {
                                this->error();
                                break;
                            }
                            this->push({{ b }}, r.value());
                            break;{% else %}    r = this->reduce_{{ a }}();
                            if (!r.has_value()) {
                                this->error();
                                break;
                            }
                            this->pop({{ g["pop_num"][a] }});
                            flag = this->GOTO(this->top_state(), LNodeType::{{ g["as"][a] }});
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r.value());
                            break;{% endif %}{% endfor %}
                        default:
                            this->error();
                            break;
                    }
                    break;
                {% endfor %}default:
                    this->error();
                    break;
            }
        }
    }

    explicit LParser(std::unique_ptr<LLexer> lexer) {
        this->lexer = std::move(lexer);
        this->move();
    }{% for rule_str in g["rule_str"] %}

    // {{ rule_str }}
    std::optional<std::shared_ptr<LNode>> reduce_{{ loop.index - 1 }}();{% endfor %}{% for T in g["Ts"] %}

    std::optional<std::shared_ptr<LNode>> shift_{{ T }}();{% endfor %}
};

#endif
"""

if __name__ == "__main__":
    g = Grammar(open("grammar.txt").read())
    for index, rule in enumerate(g.rule_str):
        print("%s\t%s" % (index, rule))
    g.gen_code()
