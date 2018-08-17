#include "LParser.h"

#include <sstream>

class LNodeChildren {
public:
    std::shared_ptr<LNode> &operator[](std::size_t i) {
        return this->children[this->children.size() - i - 1];
    }

    const std::shared_ptr<LNode> &operator[](std::size_t i) const {
        return this->children[this->children.size() - i - 1];
    }

    std::size_t size() {
        return this->children.size();
    }

    void push_front(std::shared_ptr<LNode> &&node) {
        this->children.push_back(std::move(node));
    }

    void push_front(const std::shared_ptr<LNode> &node) {
        this->children.push_back(node);
    }

    LNodeChildren() = default;

private:
    std::vector<std::shared_ptr<LNode>> children;
};

class LNodeAtom {
public:
    std::shared_ptr<LNode> expr_or_var;
    std::shared_ptr<LNode> fcalls;

    LNodeAtom(std::shared_ptr<LNode> expr_or_var, std::shared_ptr<LNode> fcalls) {
        this->expr_or_var = std::move(expr_or_var);
        this->fcalls = std::move(fcalls);
    }

    LNodeAtom() = default;
};

class LNodeExpr {
public:
    std::shared_ptr<LNode> op;
    std::shared_ptr<LNode> l;
    std::shared_ptr<LNode> r;

    LNodeExpr(std::shared_ptr<LNode> op, std::shared_ptr<LNode> l, std::shared_ptr<LNode> r) {
        this->op = std::move(op);
        this->l = std::move(l);
        this->r = std::move(r);
    }

    LNodeExpr() = default;
};

class LNodeEStmt {
public:
    std::shared_ptr<LNode> vars;
    std::shared_ptr<LNode> expr;

    LNodeEStmt(std::shared_ptr<LNode> vars, std::shared_ptr<LNode> expr) {
        this->vars = std::move(vars);
        this->expr = std::move(expr);
    }

    LNodeEStmt() = default;
};

class LNodeF0Stmt {
public:
    std::shared_ptr<LNode> var;
    std::shared_ptr<LNode> from_expr;
    std::shared_ptr<LNode> to_expr;
    std::shared_ptr<LNode> stmts;

    LNodeF0Stmt(std::shared_ptr<LNode> var, std::shared_ptr<LNode> from_expr,
                std::shared_ptr<LNode> to_expr, std::shared_ptr<LNode> stmts) {
        this->var = std::move(var);
        this->from_expr = std::move(from_expr);
        this->to_expr = std::move(to_expr);
        this->stmts = std::move(stmts);
    }

    LNodeF0Stmt() = default;
};

class LNodeF1Stmt {
public:
    std::shared_ptr<LNode> var;
    std::shared_ptr<LNode> expr;
    std::shared_ptr<LNode> stmts;

    LNodeF1Stmt(std::shared_ptr<LNode> var, std::shared_ptr<LNode> expr, std::shared_ptr<LNode> stmts) {
        this->var = std::move(var);
        this->expr = std::move(expr);
        this->stmts = std::move(stmts);
    }

    LNodeF1Stmt() = default;
};

class LNodeFCStmt {
public:
    std::shared_ptr<LNode> name;
    std::shared_ptr<LNode> parameters;
    std::shared_ptr<LNode> stmts;

    LNodeFCStmt(std::shared_ptr<LNode> name, std::shared_ptr<LNode> parameters, std::shared_ptr<LNode> stmts) {
        this->name = std::move(name);
        this->parameters = std::move(parameters);
        this->stmts = std::move(stmts);
    }

    LNodeFCStmt() = default;
};

class LNodeIEStmt {
public:
    std::shared_ptr<LNode> condition;
    std::shared_ptr<LNode> then_branch;
    std::shared_ptr<LNode> else_branch;

    LNodeIEStmt(std::shared_ptr<LNode> condition,
                std::shared_ptr<LNode> then_branch, std::shared_ptr<LNode> else_branch) {
        this->condition = std::move(condition);
        this->then_branch = std::move(then_branch);
        this->else_branch = std::move(else_branch);
    }

    LNodeIEStmt() = default;
};

class LNodeIStmt {
public:
    std::shared_ptr<LNode> condition;
    std::shared_ptr<LNode> then_branch;

    LNodeIStmt(std::shared_ptr<LNode> condition, std::shared_ptr<LNode> then_branch) {
        this->condition = std::move(condition);
        this->then_branch = std::move(then_branch);
    }

    LNodeIStmt() = default;
};

class LNodeRStmt {
public:
    std::shared_ptr<LNode> vars;

    explicit LNodeRStmt(std::shared_ptr<LNode> vars) {
        this->vars = std::move(vars);
    }

    LNodeRStmt() = default;
};


std::shared_ptr<LNode> LParser::reduce_0() {
    // Atom : BRAC Expr KET FCalls
    auto expr = this->get_node(3);
    auto fcalls = this->get_node(1);
    auto atom = std::make_shared<LNodeData<LNodeAtom>>(LNodeType::Atom, LNodeAtom(std::move(expr), std::move(fcalls)));
    return std::static_pointer_cast<LNode>(atom);
}

std::shared_ptr<LNode> LParser::reduce_1() {
    // Atom : Var FCalls
    auto var = this->get_node(2);
    auto fcalls = this->get_node(1);
    auto atom = std::make_shared<LNodeData<LNodeAtom>>(LNodeType::Atom, LNodeAtom(std::move(var), std::move(fcalls)));
    return std::static_pointer_cast<LNode>(atom);
}

std::shared_ptr<LNode> LParser::reduce_2() {
    // Atoms : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::Atoms, LNodeChildren());
}

std::shared_ptr<LNode> LParser::reduce_3() {
    // Atoms : Atom Atoms
    auto atom = this->get_node(2);
    auto atoms = this->get_node(1);
    lnode_get<LNodeChildren>(atoms)->value.push_front(std::move(atom));
    return atoms;
}

std::shared_ptr<LNode> LParser::reduce_4() {
    // BStmt : BREAK BR Brs
    return std::make_shared<LNode>(LNodeType::BStmt);
}

std::shared_ptr<LNode> LParser::reduce_5() {
    // BinOP0 : DIV
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_6() {
    // BinOP0 : MUL
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_7() {
    // BinOP1 : ADD
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_8() {
    // BinOP1 : SUB
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_9() {
    // BinOP2 : EQ
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_10() {
    // BinOP2 : G
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_11() {
    // BinOP2 : GEQ
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_12() {
    // BinOP2 : L
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_13() {
    // BinOP2 : LEQ
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_14() {
    // BinOP2 : NEQ
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_15() {
    // Brs : 
    return std::make_shared<LNode>(LNodeType::Brs);
}

std::shared_ptr<LNode> LParser::reduce_16() {
    // Brs : BR Brs
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_17() {
    // EStmt : Var Vars EQUAL Expr BR Brs
    auto var = this->get_node(6);
    auto vars = this->get_node(5);
    lnode_get<LNodeChildren>(vars)->value.push_front(std::move(var));
    auto expr = this->get_node(3);
    auto estmt = std::make_shared<LNodeData<LNodeEStmt>>(LNodeType::EStmt, LNodeEStmt(vars, expr));
    return estmt;
}

std::shared_ptr<LNode> LParser::reduce_18() {
    // Expr : Expr1
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_19() {
    // Expr : Expr1 BinOP2 Expr
    auto expr1 = this->get_node(3);
    auto op = this->get_node(2);
    auto expr = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, expr1, expr));
    return r;
}

std::shared_ptr<LNode> LParser::reduce_20() {
    // Expr0 : Atom
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_21() {
    // Expr0 : Atom BinOP0 Expr0
    auto atom = this->get_node(3);
    auto op = this->get_node(2);
    auto expr0 = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, atom, expr0));
    return r;
}

std::shared_ptr<LNode> LParser::reduce_22() {
    // Expr1 : Expr0
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_23() {
    // Expr1 : Expr0 BinOP1 Expr1
    auto atom = this->get_node(3);
    auto op = this->get_node(2);
    auto expr1 = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, atom, expr1));
    return r;
}

std::shared_ptr<LNode> LParser::reduce_24() {
    // F0Stmt : FOR Var EQUAL Expr TO Expr DO Brs Stmts END Brs
    auto var = this->get_node(10);
    auto from_expr = this->get_node(8);
    auto to_expr = this->get_node(6);
    auto stmts = this->get_node(3);
    auto r = std::make_shared<LNodeData<LNodeF0Stmt>>(
            LNodeType::F0Stmt,
            LNodeF0Stmt(std::move(var), std::move(from_expr), std::move(to_expr), std::move(stmts))
    );
    return r;
}

std::shared_ptr<LNode> LParser::reduce_25() {
    // F1Stmt : FOR Var IN Expr DO Brs Stmts END Brs
    auto var = this->get_node(8);
    auto expr = this->get_node(6);
    auto stmts = this->get_node(3);
    auto r = std::make_shared<LNodeData<LNodeF1Stmt>>(
            LNodeType::F1Stmt,
            LNodeF1Stmt(std::move(var), std::move(expr), std::move(stmts))
    );
    return r;
}

std::shared_ptr<LNode> LParser::reduce_26() {
    // FCStmt : FUNCTION Var FBRAC Vars KET Brs Stmts END Brs
    auto name = this->get_node(8);
    auto parameters = this->get_node(6);
    auto stmts = this->get_node(3);
    auto r = std::make_shared<LNodeData<LNodeFCStmt>>(
            LNodeType::FCStmt,
            LNodeFCStmt(std::move(name), std::move(parameters), std::move(stmts))
    );
    return r;
}

std::shared_ptr<LNode> LParser::reduce_27() {
    // FCall : FBRAC Atoms KET
    return this->get_node(2);
}

std::shared_ptr<LNode> LParser::reduce_28() {
    // FCalls : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::FCalls, LNodeChildren());
}

std::shared_ptr<LNode> LParser::reduce_29() {
    // FCalls : FCall FCalls
    auto fcall = this->get_node(2);
    auto fcalls = this->get_node(1);
    lnode_get<LNodeChildren>(fcalls)->value.push_front(fcall);
    return fcalls;
}

std::shared_ptr<LNode> LParser::reduce_30() {
    // IEStmt : IF Expr Brs THEN Brs NIEStmt NIEStmts ELSE Brs Stmt Stmts END Brs
    auto condition = this->get_node(12);
    auto stmt0 = this->get_node(8);
    auto then_branch = this->get_node(7);
    auto stmt1 = this->get_node(4);
    auto else_branch = this->get_node(3);
    lnode_get<LNodeChildren>(then_branch)->value.push_front(stmt0);
    lnode_get<LNodeChildren>(else_branch)->value.push_front(stmt1);
    auto r = std::make_shared<LNodeData<LNodeIEStmt>>(
            LNodeType::IEStmt,
            LNodeIEStmt(condition, then_branch, else_branch)
    );
    return r;
}

std::shared_ptr<LNode> LParser::reduce_31() {
    // IStmt : IF Expr Brs THEN Brs NIEStmts END Brs
    auto condition = this->get_node(7);
    auto then_branch = this->get_node(3);
    auto r = std::make_shared<LNodeData<LNodeIStmt>>(
            LNodeType::IStmt,
            LNodeIStmt(condition, then_branch)
    );
    return r;
}

std::shared_ptr<LNode> LParser::reduce_32() {
    // NIEStmt : BStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_33() {
    // NIEStmt : EStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_34() {
    // NIEStmt : F0Stmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_35() {
    // NIEStmt : F1Stmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_36() {
    // NIEStmt : FCStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_37() {
    // NIEStmt : IStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_38() {
    // NIEStmt : RStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_39() {
    // NIEStmt : SStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_40() {
    // NIEStmt : WStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_41() {
    // NIEStmt : YStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_42() {
    // NIEStmts : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::NIEStmt, LNodeChildren());
}

std::shared_ptr<LNode> LParser::reduce_43() {
    // NIEStmts : NIEStmt NIEStmts
    auto stmt = this->get_node(2);
    auto niestmts = this->get_node(1);
    lnode_get<LNodeChildren>(niestmts)->value.push_front(stmt);
    return niestmts;
}

std::shared_ptr<LNode> LParser::reduce_44() {
    // RStmt : RETURN Vars BR Brs
    auto vars = this->get_node(3);
    auto r = std::make_shared<LNodeData<LNodeRStmt>>(LNodeType::RStmt, LNodeRStmt(vars));
    return r;
}

std::shared_ptr<LNode> LParser::reduce_45() {
    // Root : Start
    this->accept();
    return nullptr;
}

std::shared_ptr<LNode> LParser::reduce_46() {
    // SStmt : Expr BR Brs
    return this->get_node(3);
}

std::shared_ptr<LNode> LParser::reduce_47() {
    // Start : Brs Stmts
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_48() {
    // Stmt : IEStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_49() {
    // Stmt : NIEStmt
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_50() {
    // Stmts : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::Vars, LNodeChildren());
}

std::shared_ptr<LNode> LParser::reduce_51() {
    // Stmts : Stmt Stmts
    auto stmt = this->get_node(2);
    auto stmts = this->get_node(1);
    lnode_get<LNodeChildren>(stmts)->value.push_front(stmt);
    return stmts;
}

std::shared_ptr<LNode> LParser::reduce_52() {
    // Var : INT
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_53() {
    // Var : VAR
    return this->get_node(1);
}

std::shared_ptr<LNode> LParser::reduce_54() {
    // Vars : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::Vars, LNodeChildren());
}

std::shared_ptr<LNode> LParser::reduce_55() {
    // Vars : Var Vars
    auto var = this->get_node(2);
    auto vars = this->get_node(1);
    lnode_get<LNodeChildren>(vars)->value.push_front(std::move(var));
    return vars;
}

std::shared_ptr<LNode> LParser::reduce_56() { // TODO
    // WStmt : WHILE Expr Brs DO Brs Stmts END Brs
    return nullptr;
}

std::shared_ptr<LNode> LParser::reduce_57() { // TODO
    // YStmt : YIELD Vars BR Brs
    return nullptr;
}

std::shared_ptr<LNode> LParser::shift_ADD() {
    this->move();
    return std::make_shared<LNode>(LNodeType::ADD);
}

std::shared_ptr<LNode> LParser::shift_BR() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BR);
}

std::shared_ptr<LNode> LParser::shift_BRAC() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BRAC);
}

std::shared_ptr<LNode> LParser::shift_BREAK() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BREAK);
}

std::shared_ptr<LNode> LParser::shift_DIV() {
    this->move();
    return std::make_shared<LNode>(LNodeType::DIV);
}

std::shared_ptr<LNode> LParser::shift_DO() {
    this->move();
    return std::make_shared<LNode>(LNodeType::DO);
}

std::shared_ptr<LNode> LParser::shift_ELSE() {
    this->move();
    return std::make_shared<LNode>(LNodeType::ELSE);
}

std::shared_ptr<LNode> LParser::shift_END() {
    this->move();
    return std::make_shared<LNode>(LNodeType::END);
}

std::shared_ptr<LNode> LParser::shift_EOFF() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EOFF);
}

std::shared_ptr<LNode> LParser::shift_EQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EQ);
}

std::shared_ptr<LNode> LParser::shift_EQUAL() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EQUAL);
}

std::shared_ptr<LNode> LParser::shift_FBRAC() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FBRAC);
}

std::shared_ptr<LNode> LParser::shift_FOR() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FOR);
}

std::shared_ptr<LNode> LParser::shift_FUNCTION() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FUNCTION);
}

std::shared_ptr<LNode> LParser::shift_G() {
    this->move();
    return std::make_shared<LNode>(LNodeType::G);
}

std::shared_ptr<LNode> LParser::shift_GEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::GEQ);
}

std::shared_ptr<LNode> LParser::shift_IF() {
    this->move();
    return std::make_shared<LNode>(LNodeType::IF);
}

std::shared_ptr<LNode> LParser::shift_IN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::IN);
}

std::shared_ptr<LNode> LParser::shift_INT() {
    auto r = std::make_shared<LNodeData<int64_t>>(LNodeType::INT, std::stol(this->peek->token));
    this->move();
    return r;
}

std::shared_ptr<LNode> LParser::shift_KET() {
    this->move();
    return std::make_shared<LNode>(LNodeType::KET);
}

std::shared_ptr<LNode> LParser::shift_L() {
    this->move();
    return std::make_shared<LNode>(LNodeType::L);
}

std::shared_ptr<LNode> LParser::shift_LEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::LEQ);
}

std::shared_ptr<LNode> LParser::shift_MUL() {
    this->move();
    return std::make_shared<LNode>(LNodeType::MUL);
}

std::shared_ptr<LNode> LParser::shift_NEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::NEQ);
}

std::shared_ptr<LNode> LParser::shift_RETURN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::RETURN);
}

std::shared_ptr<LNode> LParser::shift_SUB() {
    this->move();
    return std::make_shared<LNode>(LNodeType::SUB);
}

std::shared_ptr<LNode> LParser::shift_THEN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::THEN);
}

std::shared_ptr<LNode> LParser::shift_TO() {
    this->move();
    return std::make_shared<LNode>(LNodeType::TO);
}

std::shared_ptr<LNode> LParser::shift_VAR() {
    auto r = std::make_shared<LNodeData<std::string>>(LNodeType::VAR, this->peek->token);
    this->move();
    return r;
}

std::shared_ptr<LNode> LParser::shift_WHILE() {
    this->move();
    return std::make_shared<LNode>(LNodeType::WHILE);
}

std::shared_ptr<LNode> LParser::shift_YIELD() {
    this->move();
    return std::make_shared<LNode>(LNodeType::YIELD);
}
