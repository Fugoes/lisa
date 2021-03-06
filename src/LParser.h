#ifndef LISA_LPARSER_H
#define LISA_LPARSER_H

#include "LLexer.h"
#include "LNode.h"

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <exception>

class LParserException : std::exception {
public:
    std::string detail;

    explicit LParserException(std::string &&detail) {
        this->detail = std::move(detail);
    }

    virtual const char *what() const throw() {
        return this->detail.c_str();
    }
};

class LParser {
public:
    std::unique_ptr<LLexer> lexer;

    std::shared_ptr<LToken> peek;

    std::vector<int> state_stack;

    std::vector<std::shared_ptr<LNode>> node_stack;

    void error() {
        throw LParserException("ERROR");
    }

    void accept() {
        throw LParserException("ACCEPT");
    }

    std::shared_ptr<LNode> get_node(int i) {
        return this->node_stack[this->node_stack.size() - i];
    }

    void move() {
        this->peek = this->lexer->next_token();
        std::cout << this->peek->str() << std::endl;
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
            case 0:
                switch (node_type) {
                    case LNodeType::Start:
                        return 2;
                    case LNodeType::Brs:
                        return 3;
                    default:
                        this->error();
                        return -1;
                }
            case 1:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 4;
                    default:
                        this->error();
                        return -1;
                }
            case 3:
                switch (node_type) {
                    case LNodeType::Var:
                        return 6;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 14;
                    case LNodeType::EStmt:
                        return 15;
                    case LNodeType::F0Stmt:
                        return 16;
                    case LNodeType::F1Stmt:
                        return 17;
                    case LNodeType::FCStmt:
                        return 18;
                    case LNodeType::IStmt:
                        return 19;
                    case LNodeType::RStmt:
                        return 20;
                    case LNodeType::SStmt:
                        return 21;
                    case LNodeType::WStmt:
                        return 22;
                    case LNodeType::YStmt:
                        return 23;
                    case LNodeType::Expr:
                        return 25;
                    case LNodeType::Stmts:
                        return 26;
                    case LNodeType::IEStmt:
                        return 27;
                    case LNodeType::NIEStmt:
                        return 28;
                    case LNodeType::Stmt:
                        return 29;
                    default:
                        this->error();
                        return -1;
                }
            case 5:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 36;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 6:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::Vars:
                        return 43;
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::Var:
                        return 48;
                    default:
                        this->error();
                        return -1;
                }
            case 8:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 56;
                    default:
                        this->error();
                        return -1;
                }
            case 9:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 59;
                    default:
                        this->error();
                        return -1;
                }
            case 10:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 62;
                    default:
                        this->error();
                        return -1;
                }
            case 11:
                switch (node_type) {
                    case LNodeType::Var:
                        return 63;
                    default:
                        this->error();
                        return -1;
                }
            case 12:
                switch (node_type) {
                    case LNodeType::Var:
                        return 66;
                    default:
                        this->error();
                        return -1;
                }
            case 13:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Expr1:
                        return 71;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    case LNodeType::Expr:
                        return 74;
                    default:
                        this->error();
                        return -1;
                }
            case 24:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 77;
                    case LNodeType::Var:
                        return 80;
                    default:
                        this->error();
                        return -1;
                }
            case 29:
                switch (node_type) {
                    case LNodeType::Var:
                        return 6;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 14;
                    case LNodeType::EStmt:
                        return 15;
                    case LNodeType::F0Stmt:
                        return 16;
                    case LNodeType::F1Stmt:
                        return 17;
                    case LNodeType::FCStmt:
                        return 18;
                    case LNodeType::IStmt:
                        return 19;
                    case LNodeType::RStmt:
                        return 20;
                    case LNodeType::SStmt:
                        return 21;
                    case LNodeType::WStmt:
                        return 22;
                    case LNodeType::YStmt:
                        return 23;
                    case LNodeType::Expr:
                        return 25;
                    case LNodeType::IEStmt:
                        return 27;
                    case LNodeType::NIEStmt:
                        return 28;
                    case LNodeType::Stmt:
                        return 29;
                    case LNodeType::Stmts:
                        return 82;
                    default:
                        this->error();
                        return -1;
                }
            case 32:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Expr1:
                        return 85;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 87;
                    case LNodeType::Expr:
                        return 90;
                    default:
                        this->error();
                        return -1;
                }
            case 33:
                switch (node_type) {
                    case LNodeType::Var:
                        return 80;
                    case LNodeType::Vars:
                        return 91;
                    default:
                        this->error();
                        return -1;
                }
            case 34:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 92;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 35:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 93;
                    case LNodeType::FCall:
                        return 95;
                    default:
                        this->error();
                        return -1;
                }
            case 37:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 97;
                    default:
                        this->error();
                        return -1;
                }
            case 38:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 98;
                    default:
                        this->error();
                        return -1;
                }
            case 39:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 99;
                    default:
                        this->error();
                        return -1;
                }
            case 44:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 104;
                    default:
                        this->error();
                        return -1;
                }
            case 45:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::FCalls:
                        return 107;
                    default:
                        this->error();
                        return -1;
                }
            case 48:
                switch (node_type) {
                    case LNodeType::Var:
                        return 48;
                    case LNodeType::Vars:
                        return 108;
                    default:
                        this->error();
                        return -1;
                }
            case 49:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 109;
                    default:
                        this->error();
                        return -1;
                }
            case 56:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Expr:
                        return 111;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        this->error();
                        return -1;
                }
            case 59:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 114;
                    default:
                        this->error();
                        return -1;
                }
            case 62:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Expr1:
                        return 115;
                    default:
                        this->error();
                        return -1;
                }
            case 69:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 119;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 70:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 120;
                    case LNodeType::FCall:
                        return 122;
                    default:
                        this->error();
                        return -1;
                }
            case 71:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 123;
                    default:
                        this->error();
                        return -1;
                }
            case 72:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 124;
                    default:
                        this->error();
                        return -1;
                }
            case 73:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 125;
                    default:
                        this->error();
                        return -1;
                }
            case 74:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 127;
                    default:
                        this->error();
                        return -1;
                }
            case 80:
                switch (node_type) {
                    case LNodeType::Var:
                        return 80;
                    case LNodeType::Vars:
                        return 129;
                    default:
                        this->error();
                        return -1;
                }
            case 81:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 130;
                    default:
                        this->error();
                        return -1;
                }
            case 83:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 131;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 84:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 132;
                    case LNodeType::FCall:
                        return 134;
                    default:
                        this->error();
                        return -1;
                }
            case 85:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 135;
                    default:
                        this->error();
                        return -1;
                }
            case 86:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 136;
                    default:
                        this->error();
                        return -1;
                }
            case 87:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 137;
                    default:
                        this->error();
                        return -1;
                }
            case 90:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 139;
                    default:
                        this->error();
                        return -1;
                }
            case 94:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 142;
                    default:
                        this->error();
                        return -1;
                }
            case 95:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 95;
                    case LNodeType::FCalls:
                        return 143;
                    default:
                        this->error();
                        return -1;
                }
            case 96:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 144;
                    case LNodeType::FCall:
                        return 45;
                    default:
                        this->error();
                        return -1;
                }
            case 97:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Expr:
                        return 145;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 98:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 146;
                    default:
                        this->error();
                        return -1;
                }
            case 99:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    case LNodeType::Expr1:
                        return 147;
                    default:
                        this->error();
                        return -1;
                }
            case 100:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Expr:
                        return 148;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        this->error();
                        return -1;
                }
            case 101:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 149;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 102:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 150;
                    case LNodeType::FCall:
                        return 152;
                    default:
                        this->error();
                        return -1;
                }
            case 103:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 153;
                    default:
                        this->error();
                        return -1;
                }
            case 110:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::FCall:
                        return 45;
                    default:
                        this->error();
                        return -1;
                }
            case 116:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Expr1:
                        return 157;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 159;
                    case LNodeType::Expr:
                        return 160;
                    default:
                        this->error();
                        return -1;
                }
            case 117:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 168;
                    default:
                        this->error();
                        return -1;
                }
            case 118:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 171;
                    case LNodeType::Var:
                        return 174;
                    default:
                        this->error();
                        return -1;
                }
            case 121:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 176;
                    default:
                        this->error();
                        return -1;
                }
            case 122:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 122;
                    case LNodeType::FCalls:
                        return 177;
                    default:
                        this->error();
                        return -1;
                }
            case 123:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Expr1:
                        return 71;
                    case LNodeType::Expr:
                        return 178;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    default:
                        this->error();
                        return -1;
                }
            case 124:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 179;
                    default:
                        this->error();
                        return -1;
                }
            case 125:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    case LNodeType::Expr1:
                        return 180;
                    default:
                        this->error();
                        return -1;
                }
            case 126:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 181;
                    default:
                        this->error();
                        return -1;
                }
            case 128:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 183;
                    default:
                        this->error();
                        return -1;
                }
            case 133:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 185;
                    default:
                        this->error();
                        return -1;
                }
            case 134:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 134;
                    case LNodeType::FCalls:
                        return 186;
                    default:
                        this->error();
                        return -1;
                }
            case 135:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Expr1:
                        return 85;
                    case LNodeType::Expr:
                        return 187;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 87;
                    default:
                        this->error();
                        return -1;
                }
            case 136:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 188;
                    default:
                        this->error();
                        return -1;
                }
            case 137:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 87;
                    case LNodeType::Expr1:
                        return 189;
                    default:
                        this->error();
                        return -1;
                }
            case 138:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 190;
                    default:
                        this->error();
                        return -1;
                }
            case 140:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 192;
                    default:
                        this->error();
                        return -1;
                }
            case 141:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 193;
                    case LNodeType::FCall:
                        return 95;
                    default:
                        this->error();
                        return -1;
                }
            case 151:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 197;
                    default:
                        this->error();
                        return -1;
                }
            case 152:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 152;
                    case LNodeType::FCalls:
                        return 198;
                    default:
                        this->error();
                        return -1;
                }
            case 155:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 199;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 156:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 200;
                    case LNodeType::FCall:
                        return 202;
                    default:
                        this->error();
                        return -1;
                }
            case 157:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 203;
                    default:
                        this->error();
                        return -1;
                }
            case 158:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 204;
                    default:
                        this->error();
                        return -1;
                }
            case 159:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 205;
                    default:
                        this->error();
                        return -1;
                }
            case 163:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 207;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        this->error();
                        return -1;
                }
            case 164:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 208;
                    case LNodeType::FCall:
                        return 210;
                    default:
                        this->error();
                        return -1;
                }
            case 165:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 211;
                    default:
                        this->error();
                        return -1;
                }
            case 166:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 212;
                    default:
                        this->error();
                        return -1;
                }
            case 167:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 213;
                    default:
                        this->error();
                        return -1;
                }
            case 174:
                switch (node_type) {
                    case LNodeType::Var:
                        return 174;
                    case LNodeType::Vars:
                        return 216;
                    default:
                        this->error();
                        return -1;
                }
            case 175:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 217;
                    case LNodeType::FCall:
                        return 122;
                    default:
                        this->error();
                        return -1;
                }
            case 182:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 220;
                    default:
                        this->error();
                        return -1;
                }
            case 184:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 221;
                    case LNodeType::FCall:
                        return 134;
                    default:
                        this->error();
                        return -1;
                }
            case 191:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 223;
                    default:
                        this->error();
                        return -1;
                }
            case 195:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 224;
                    default:
                        this->error();
                        return -1;
                }
            case 196:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 225;
                    case LNodeType::FCall:
                        return 152;
                    default:
                        this->error();
                        return -1;
                }
            case 201:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 228;
                    default:
                        this->error();
                        return -1;
                }
            case 202:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 202;
                    case LNodeType::FCalls:
                        return 229;
                    default:
                        this->error();
                        return -1;
                }
            case 203:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Expr1:
                        return 157;
                    case LNodeType::Expr:
                        return 230;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 159;
                    default:
                        this->error();
                        return -1;
                }
            case 204:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 231;
                    default:
                        this->error();
                        return -1;
                }
            case 205:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 159;
                    case LNodeType::Expr1:
                        return 232;
                    default:
                        this->error();
                        return -1;
                }
            case 206:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 233;
                    default:
                        this->error();
                        return -1;
                }
            case 209:
                switch (node_type) {
                    case LNodeType::Var:
                        return 102;
                    case LNodeType::Atom:
                        return 103;
                    case LNodeType::Atoms:
                        return 235;
                    default:
                        this->error();
                        return -1;
                }
            case 210:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 210;
                    case LNodeType::FCalls:
                        return 236;
                    default:
                        this->error();
                        return -1;
                }
            case 211:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Expr:
                        return 237;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    default:
                        this->error();
                        return -1;
                }
            case 212:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 238;
                    default:
                        this->error();
                        return -1;
                }
            case 213:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr1:
                        return 239;
                    default:
                        this->error();
                        return -1;
                }
            case 214:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 240;
                    default:
                        this->error();
                        return -1;
                }
            case 215:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 241;
                    default:
                        this->error();
                        return -1;
                }
            case 219:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 242;
                    default:
                        this->error();
                        return -1;
                }
            case 220:
                switch (node_type) {
                    case LNodeType::Var:
                        return 243;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmt:
                        return 247;
                    case LNodeType::NIEStmts:
                        return 249;
                    case LNodeType::BStmt:
                        return 250;
                    case LNodeType::EStmt:
                        return 251;
                    case LNodeType::F0Stmt:
                        return 252;
                    case LNodeType::F1Stmt:
                        return 253;
                    case LNodeType::FCStmt:
                        return 254;
                    case LNodeType::IStmt:
                        return 255;
                    case LNodeType::RStmt:
                        return 256;
                    case LNodeType::SStmt:
                        return 257;
                    case LNodeType::WStmt:
                        return 258;
                    case LNodeType::YStmt:
                        return 259;
                    case LNodeType::Expr:
                        return 261;
                    default:
                        this->error();
                        return -1;
                }
            case 223:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    case LNodeType::Stmts:
                        return 285;
                    default:
                        this->error();
                        return -1;
                }
            case 227:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 287;
                    case LNodeType::FCall:
                        return 202;
                    default:
                        this->error();
                        return -1;
                }
            case 234:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 290;
                    case LNodeType::FCall:
                        return 210;
                    default:
                        this->error();
                        return -1;
                }
            case 240:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 292;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 241:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 293;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 243:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::Vars:
                        return 294;
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::Var:
                        return 48;
                    default:
                        this->error();
                        return -1;
                }
            case 245:
                switch (node_type) {
                    case LNodeType::Var:
                        return 296;
                    default:
                        this->error();
                        return -1;
                }
            case 246:
                switch (node_type) {
                    case LNodeType::Var:
                        return 297;
                    default:
                        this->error();
                        return -1;
                }
            case 247:
                switch (node_type) {
                    case LNodeType::Var:
                        return 243;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 298;
                    case LNodeType::BStmt:
                        return 250;
                    case LNodeType::EStmt:
                        return 251;
                    case LNodeType::F0Stmt:
                        return 252;
                    case LNodeType::F1Stmt:
                        return 253;
                    case LNodeType::FCStmt:
                        return 254;
                    case LNodeType::IStmt:
                        return 255;
                    case LNodeType::RStmt:
                        return 256;
                    case LNodeType::SStmt:
                        return 257;
                    case LNodeType::WStmt:
                        return 258;
                    case LNodeType::YStmt:
                        return 259;
                    case LNodeType::NIEStmt:
                        return 299;
                    case LNodeType::Expr:
                        return 261;
                    default:
                        this->error();
                        return -1;
                }
            case 248:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Expr1:
                        return 71;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    case LNodeType::Expr:
                        return 300;
                    default:
                        this->error();
                        return -1;
                }
            case 260:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 302;
                    case LNodeType::Var:
                        return 80;
                    default:
                        this->error();
                        return -1;
                }
            case 262:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Expr1:
                        return 85;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 87;
                    case LNodeType::Expr:
                        return 304;
                    default:
                        this->error();
                        return -1;
                }
            case 263:
                switch (node_type) {
                    case LNodeType::Var:
                        return 80;
                    case LNodeType::Vars:
                        return 305;
                    default:
                        this->error();
                        return -1;
                }
            case 264:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::Vars:
                        return 306;
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::Var:
                        return 48;
                    default:
                        this->error();
                        return -1;
                }
            case 266:
                switch (node_type) {
                    case LNodeType::Var:
                        return 308;
                    default:
                        this->error();
                        return -1;
                }
            case 267:
                switch (node_type) {
                    case LNodeType::Var:
                        return 309;
                    default:
                        this->error();
                        return -1;
                }
            case 268:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Expr1:
                        return 71;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    case LNodeType::Expr:
                        return 310;
                    default:
                        this->error();
                        return -1;
                }
            case 279:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 311;
                    case LNodeType::Var:
                        return 80;
                    default:
                        this->error();
                        return -1;
                }
            case 283:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    case LNodeType::Stmts:
                        return 313;
                    default:
                        this->error();
                        return -1;
                }
            case 284:
                switch (node_type) {
                    case LNodeType::Var:
                        return 84;
                    case LNodeType::Expr1:
                        return 85;
                    case LNodeType::Atom:
                        return 86;
                    case LNodeType::Expr0:
                        return 87;
                    case LNodeType::Expr:
                        return 314;
                    default:
                        this->error();
                        return -1;
                }
            case 286:
                switch (node_type) {
                    case LNodeType::Var:
                        return 80;
                    case LNodeType::Vars:
                        return 316;
                    default:
                        this->error();
                        return -1;
                }
            case 289:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 317;
                    default:
                        this->error();
                        return -1;
                }
            case 295:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 321;
                    default:
                        this->error();
                        return -1;
                }
            case 299:
                switch (node_type) {
                    case LNodeType::Var:
                        return 243;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 250;
                    case LNodeType::EStmt:
                        return 251;
                    case LNodeType::F0Stmt:
                        return 252;
                    case LNodeType::F1Stmt:
                        return 253;
                    case LNodeType::FCStmt:
                        return 254;
                    case LNodeType::IStmt:
                        return 255;
                    case LNodeType::RStmt:
                        return 256;
                    case LNodeType::SStmt:
                        return 257;
                    case LNodeType::WStmt:
                        return 258;
                    case LNodeType::YStmt:
                        return 259;
                    case LNodeType::NIEStmt:
                        return 299;
                    case LNodeType::NIEStmts:
                        return 327;
                    case LNodeType::Expr:
                        return 261;
                    default:
                        this->error();
                        return -1;
                }
            case 300:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 328;
                    default:
                        this->error();
                        return -1;
                }
            case 301:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 329;
                    default:
                        this->error();
                        return -1;
                }
            case 303:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 331;
                    default:
                        this->error();
                        return -1;
                }
            case 304:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 332;
                    default:
                        this->error();
                        return -1;
                }
            case 307:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 335;
                    default:
                        this->error();
                        return -1;
                }
            case 310:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 339;
                    default:
                        this->error();
                        return -1;
                }
            case 312:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 341;
                    default:
                        this->error();
                        return -1;
                }
            case 314:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 342;
                    default:
                        this->error();
                        return -1;
                }
            case 315:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 343;
                    default:
                        this->error();
                        return -1;
                }
            case 317:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 345;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 318:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 346;
                    default:
                        this->error();
                        return -1;
                }
            case 319:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 347;
                    default:
                        this->error();
                        return -1;
                }
            case 320:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Expr:
                        return 348;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        this->error();
                        return -1;
                }
            case 322:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 349;
                    default:
                        this->error();
                        return -1;
                }
            case 323:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Expr1:
                        return 157;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 159;
                    case LNodeType::Expr:
                        return 350;
                    default:
                        this->error();
                        return -1;
                }
            case 324:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 351;
                    default:
                        this->error();
                        return -1;
                }
            case 325:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 352;
                    case LNodeType::Var:
                        return 174;
                    default:
                        this->error();
                        return -1;
                }
            case 326:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 354;
                    default:
                        this->error();
                        return -1;
                }
            case 330:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 356;
                    default:
                        this->error();
                        return -1;
                }
            case 333:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 358;
                    default:
                        this->error();
                        return -1;
                }
            case 334:
                switch (node_type) {
                    case LNodeType::Var:
                        return 110;
                    case LNodeType::Expr:
                        return 359;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        this->error();
                        return -1;
                }
            case 336:
                switch (node_type) {
                    case LNodeType::Var:
                        return 156;
                    case LNodeType::Expr1:
                        return 157;
                    case LNodeType::Atom:
                        return 158;
                    case LNodeType::Expr0:
                        return 159;
                    case LNodeType::Expr:
                        return 360;
                    default:
                        this->error();
                        return -1;
                }
            case 337:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 361;
                    default:
                        this->error();
                        return -1;
                }
            case 338:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 362;
                    case LNodeType::Var:
                        return 174;
                    default:
                        this->error();
                        return -1;
                }
            case 340:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 364;
                    default:
                        this->error();
                        return -1;
                }
            case 344:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 366;
                    default:
                        this->error();
                        return -1;
                }
            case 353:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 372;
                    default:
                        this->error();
                        return -1;
                }
            case 354:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmt:
                        return 373;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    default:
                        this->error();
                        return -1;
                }
            case 355:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 374;
                    default:
                        this->error();
                        return -1;
                }
            case 357:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 375;
                    default:
                        this->error();
                        return -1;
                }
            case 363:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 380;
                    default:
                        this->error();
                        return -1;
                }
            case 365:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 381;
                    default:
                        this->error();
                        return -1;
                }
            case 367:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 382;
                    default:
                        this->error();
                        return -1;
                }
            case 368:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 383;
                    default:
                        this->error();
                        return -1;
                }
            case 369:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 384;
                    default:
                        this->error();
                        return -1;
                }
            case 370:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 385;
                    default:
                        this->error();
                        return -1;
                }
            case 371:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 386;
                    default:
                        this->error();
                        return -1;
                }
            case 373:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 387;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 374:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 389;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::NIEStmt:
                        return 390;
                    case LNodeType::Expr:
                        return 280;
                    default:
                        this->error();
                        return -1;
                }
            case 375:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    case LNodeType::Stmts:
                        return 391;
                    default:
                        this->error();
                        return -1;
                }
            case 376:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 392;
                    default:
                        this->error();
                        return -1;
                }
            case 377:
                switch (node_type) {
                    case LNodeType::Var:
                        return 164;
                    case LNodeType::Expr1:
                        return 165;
                    case LNodeType::Atom:
                        return 166;
                    case LNodeType::Expr0:
                        return 167;
                    case LNodeType::Expr:
                        return 393;
                    default:
                        this->error();
                        return -1;
                }
            case 378:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 394;
                    default:
                        this->error();
                        return -1;
                }
            case 379:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 395;
                    default:
                        this->error();
                        return -1;
                }
            case 380:
                switch (node_type) {
                    case LNodeType::Var:
                        return 243;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmt:
                        return 396;
                    case LNodeType::NIEStmts:
                        return 397;
                    case LNodeType::BStmt:
                        return 250;
                    case LNodeType::EStmt:
                        return 251;
                    case LNodeType::F0Stmt:
                        return 252;
                    case LNodeType::F1Stmt:
                        return 253;
                    case LNodeType::FCStmt:
                        return 254;
                    case LNodeType::IStmt:
                        return 255;
                    case LNodeType::RStmt:
                        return 256;
                    case LNodeType::SStmt:
                        return 257;
                    case LNodeType::WStmt:
                        return 258;
                    case LNodeType::YStmt:
                        return 259;
                    case LNodeType::Expr:
                        return 261;
                    default:
                        this->error();
                        return -1;
                }
            case 381:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    case LNodeType::Stmts:
                        return 398;
                    default:
                        this->error();
                        return -1;
                }
            case 385:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 400;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 386:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 401;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 388:
                switch (node_type) {
                    case LNodeType::Var:
                        return 70;
                    case LNodeType::Expr1:
                        return 71;
                    case LNodeType::Atom:
                        return 72;
                    case LNodeType::Expr0:
                        return 73;
                    case LNodeType::Expr:
                        return 403;
                    default:
                        this->error();
                        return -1;
                }
            case 390:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::NIEStmt:
                        return 390;
                    case LNodeType::NIEStmts:
                        return 405;
                    case LNodeType::Expr:
                        return 280;
                    default:
                        this->error();
                        return -1;
                }
            case 394:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 408;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 395:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 409;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 396:
                switch (node_type) {
                    case LNodeType::Var:
                        return 243;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 410;
                    case LNodeType::BStmt:
                        return 250;
                    case LNodeType::EStmt:
                        return 251;
                    case LNodeType::F0Stmt:
                        return 252;
                    case LNodeType::F1Stmt:
                        return 253;
                    case LNodeType::FCStmt:
                        return 254;
                    case LNodeType::IStmt:
                        return 255;
                    case LNodeType::RStmt:
                        return 256;
                    case LNodeType::SStmt:
                        return 257;
                    case LNodeType::WStmt:
                        return 258;
                    case LNodeType::YStmt:
                        return 259;
                    case LNodeType::NIEStmt:
                        return 299;
                    case LNodeType::Expr:
                        return 261;
                    default:
                        this->error();
                        return -1;
                }
            case 399:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 413;
                    default:
                        this->error();
                        return -1;
                }
            case 402:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 416;
                    default:
                        this->error();
                        return -1;
                }
            case 403:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 417;
                    default:
                        this->error();
                        return -1;
                }
            case 404:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 418;
                    default:
                        this->error();
                        return -1;
                }
            case 406:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 419;
                    default:
                        this->error();
                        return -1;
                }
            case 407:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 420;
                    default:
                        this->error();
                        return -1;
                }
            case 411:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 424;
                    default:
                        this->error();
                        return -1;
                }
            case 412:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 425;
                    default:
                        this->error();
                        return -1;
                }
            case 413:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 426;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 414:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 427;
                    default:
                        this->error();
                        return -1;
                }
            case 415:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 428;
                    default:
                        this->error();
                        return -1;
                }
            case 420:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 430;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 421:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 431;
                    default:
                        this->error();
                        return -1;
                }
            case 422:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 432;
                    default:
                        this->error();
                        return -1;
                }
            case 423:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 433;
                    default:
                        this->error();
                        return -1;
                }
            case 429:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 435;
                    default:
                        this->error();
                        return -1;
                }
            case 433:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmt:
                        return 437;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    default:
                        this->error();
                        return -1;
                }
            case 434:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 438;
                    default:
                        this->error();
                        return -1;
                }
            case 435:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 397;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::NIEStmt:
                        return 390;
                    case LNodeType::Expr:
                        return 280;
                    default:
                        this->error();
                        return -1;
                }
            case 436:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 439;
                    default:
                        this->error();
                        return -1;
                }
            case 437:
                switch (node_type) {
                    case LNodeType::Var:
                        return 264;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 440;
                    case LNodeType::BStmt:
                        return 269;
                    case LNodeType::EStmt:
                        return 270;
                    case LNodeType::F0Stmt:
                        return 271;
                    case LNodeType::F1Stmt:
                        return 272;
                    case LNodeType::FCStmt:
                        return 273;
                    case LNodeType::IStmt:
                        return 274;
                    case LNodeType::RStmt:
                        return 275;
                    case LNodeType::SStmt:
                        return 276;
                    case LNodeType::WStmt:
                        return 277;
                    case LNodeType::YStmt:
                        return 278;
                    case LNodeType::Expr:
                        return 280;
                    case LNodeType::IEStmt:
                        return 281;
                    case LNodeType::NIEStmt:
                        return 282;
                    case LNodeType::Stmt:
                        return 283;
                    default:
                        this->error();
                        return -1;
                }
            case 441:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 442;
                    default:
                        this->error();
                        return -1;
                }
            default:
                this->error();
                return -1;
        }
    }

    int top_state() {
        return this->state_stack[this->node_stack.size() - 1];
    }

    void parse() {
        this->push(0, nullptr);
        std::shared_ptr<LNode> r;
        try {
            while (true) {
                switch (this->top_state()) {
                    case 0:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 1:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 2:
                        switch (this->peek->type) {
                            case LNodeType::EOFF:
                                r = this->reduce_45();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Root), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 3:
                        switch (this->peek->type) {
                            case LNodeType::EOFF:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(7, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(11, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(12, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(13, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(24, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(32, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(33, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 4:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 5:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 6:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::EQUAL:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(46, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(47, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 7:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(49, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 8:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 9:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 10:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 11:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(64, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(65, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 12:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(67, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(68, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 13:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 14:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_32();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 15:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_33();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 16:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_34();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 17:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_35();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 18:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_36();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 19:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_37();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 20:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_38();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 21:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_39();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 22:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_40();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 23:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_41();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 24:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 25:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(81, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 26:
                        switch (this->peek->type) {
                            case LNodeType::EOFF:
                                r = this->reduce_47();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Start), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 27:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_48();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 28:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_49();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 29:
                        switch (this->peek->type) {
                            case LNodeType::EOFF:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(7, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(11, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(12, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(13, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(24, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(32, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(33, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 30:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::EQUAL:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::INT:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::VAR:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 31:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::EQUAL:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::INT:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::VAR:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 32:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 33:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 34:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 35:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(94, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 36:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(96, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 37:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 38:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 39:
                        switch (this->peek->type) {
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 40:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 41:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 42:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 43:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(100, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 44:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 45:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 46:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 47:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 48:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(46, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(47, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 49:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 50:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_9();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 51:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_10();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 52:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_11();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 53:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_12();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 54:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_13();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 55:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_14();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP2), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 56:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 57:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_5();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 58:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_6();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 59:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 60:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_7();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 61:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_8();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::BinOP1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 62:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 63:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(116, r);
                                break;
                            case LNodeType::IN:
                                r = this->shift_IN();
                                this->push(117, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 64:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                            case LNodeType::IN:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 65:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                            case LNodeType::IN:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 66:
                        switch (this->peek->type) {
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(118, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 67:
                        switch (this->peek->type) {
                            case LNodeType::FBRAC:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 68:
                        switch (this->peek->type) {
                            case LNodeType::FBRAC:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 69:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 70:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(121, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 71:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::THEN:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 72:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 73:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::THEN:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 74:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(126, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 75:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 76:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 77:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(128, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 78:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 79:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::INT:
                            case LNodeType::VAR:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 80:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 81:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 82:
                        switch (this->peek->type) {
                            case LNodeType::EOFF:
                                r = this->reduce_51();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 83:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 84:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(133, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 85:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::DO:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 86:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 87:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 88:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 89:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 90:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(138, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 91:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(140, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 92:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(141, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 93:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 94:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 95:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(94, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 96:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 97:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 98:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 99:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 100:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 101:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 102:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(151, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 103:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 104:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(154, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 105:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::FBRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 106:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::FBRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 107:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 108:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->reduce_55();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 109:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_4();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::BStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 110:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 111:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 112:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 113:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 114:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 115:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 116:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 117:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 118:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(172, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(173, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 119:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(175, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 120:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 121:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 122:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(121, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 123:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 124:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 125:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 126:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(126, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 127:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->shift_THEN();
                                this->push(182, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 128:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 129:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_55();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 130:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_46();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::SStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 131:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(184, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 132:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 133:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 134:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(133, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 135:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 136:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 137:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 138:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(138, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 139:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(191, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 140:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 141:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(94, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 142:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(194, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 143:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 144:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 145:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 146:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 147:
                        switch (this->peek->type) {
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 148:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(195, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 149:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(196, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 150:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 151:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 152:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(151, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 153:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_3();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 154:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 155:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 156:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(201, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 157:
                        switch (this->peek->type) {
                            case LNodeType::TO:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 158:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 159:
                        switch (this->peek->type) {
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::TO:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 160:
                        switch (this->peek->type) {
                            case LNodeType::TO:
                                r = this->shift_TO();
                                this->push(206, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 161:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 162:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 163:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(34, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(40, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(41, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 164:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(209, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 165:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_18();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            case LNodeType::EQ:
                                r = this->shift_EQ();
                                this->push(50, r);
                                break;
                            case LNodeType::G:
                                r = this->shift_G();
                                this->push(51, r);
                                break;
                            case LNodeType::GEQ:
                                r = this->shift_GEQ();
                                this->push(52, r);
                                break;
                            case LNodeType::L:
                                r = this->shift_L();
                                this->push(53, r);
                                break;
                            case LNodeType::LEQ:
                                r = this->shift_LEQ();
                                this->push(54, r);
                                break;
                            case LNodeType::NEQ:
                                r = this->shift_NEQ();
                                this->push(55, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 166:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_20();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            case LNodeType::DIV:
                                r = this->shift_DIV();
                                this->push(57, r);
                                break;
                            case LNodeType::MUL:
                                r = this->shift_MUL();
                                this->push(58, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 167:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_22();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            case LNodeType::ADD:
                                r = this->shift_ADD();
                                this->push(60, r);
                                break;
                            case LNodeType::SUB:
                                r = this->shift_SUB();
                                this->push(61, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 168:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(214, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 169:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 170:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 171:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(215, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 172:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_52();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 173:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_53();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Var), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 174:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(172, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(173, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 175:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(121, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 176:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(218, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 177:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 178:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::THEN:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 179:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 180:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::THEN:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 181:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 182:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 183:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_44();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::RStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 184:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(133, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 185:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(222, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 186:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 187:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::DO:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 188:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 189:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 190:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 191:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 192:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_57();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::YStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 193:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 194:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::KET:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 195:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 196:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(151, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 197:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(226, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 198:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 199:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(227, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 200:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 201:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 202:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(201, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 203:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 204:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 205:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 206:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 207:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(234, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 208:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_1();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 209:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_2();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atoms), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(101, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(105, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(106, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 210:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(209, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 211:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 212:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 213:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 214:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 215:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 216:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_55();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 217:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 218:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::THEN:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 219:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 220:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(244, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(245, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(246, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(248, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(260, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(262, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(263, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 221:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 222:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 223:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 224:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_17();
                                this->pop(6);
                                this->push(this->GOTO(this->top_state(), LNodeType::EStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 225:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 226:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::FBRAC:
                            case LNodeType::INT:
                            case LNodeType::KET:
                            case LNodeType::VAR:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 227:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(201, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 228:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(288, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 229:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 230:
                        switch (this->peek->type) {
                            case LNodeType::TO:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 231:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 232:
                        switch (this->peek->type) {
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::TO:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 233:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(289, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 234:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(209, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 235:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(291, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 236:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_29();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 237:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_19();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 238:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_21();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr0), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 239:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::NEQ:
                                r = this->reduce_23();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::Expr1), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 240:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 241:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 242:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 243:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::EQUAL:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(46, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(47, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 244:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(295, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 245:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(64, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(65, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 246:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(67, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(68, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 247:
                        switch (this->peek->type) {
                            case LNodeType::ELSE:
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(244, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(245, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(246, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(248, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(260, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(262, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(263, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 248:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 249:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(301, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 250:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_32();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 251:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_33();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 252:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_34();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 253:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_35();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 254:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_36();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 255:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_37();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 256:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_38();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 257:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_39();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 258:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_40();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 259:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_41();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 260:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 261:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(303, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 262:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 263:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 264:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::BR:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_28();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCalls), r);
                                break;
                            case LNodeType::EQUAL:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(44, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(46, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(47, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 265:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(307, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 266:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(64, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(65, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 267:
                        switch (this->peek->type) {
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(67, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(68, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 268:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 269:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_32();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 270:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_33();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 271:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_34();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 272:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_35();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 273:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_36();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 274:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_37();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 275:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_38();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 276:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_39();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 277:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_40();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 278:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_41();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 279:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 280:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(312, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 281:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_48();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 282:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_49();
                                this->pop(1);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 283:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 284:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(83, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(88, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(89, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 285:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(315, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 286:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(78, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(79, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 287:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 288:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                            case LNodeType::TO:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 289:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 290:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_0();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::Atom), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 291:
                        switch (this->peek->type) {
                            case LNodeType::ADD:
                            case LNodeType::DIV:
                            case LNodeType::DO:
                            case LNodeType::EQ:
                            case LNodeType::FBRAC:
                            case LNodeType::G:
                            case LNodeType::GEQ:
                            case LNodeType::L:
                            case LNodeType::LEQ:
                            case LNodeType::MUL:
                            case LNodeType::NEQ:
                            case LNodeType::SUB:
                                r = this->reduce_27();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCall), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 292:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(318, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 293:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(319, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 294:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(320, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 295:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 296:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(323, r);
                                break;
                            case LNodeType::IN:
                                r = this->shift_IN();
                                this->push(324, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 297:
                        switch (this->peek->type) {
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(325, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 298:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_43();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::ELSE:
                                r = this->shift_ELSE();
                                this->push(326, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 299:
                        switch (this->peek->type) {
                            case LNodeType::ELSE:
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(244, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(245, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(246, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(248, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(260, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(262, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(263, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 300:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(126, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 301:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 302:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(330, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 303:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 304:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(138, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 305:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(333, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 306:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(334, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 307:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 308:
                        switch (this->peek->type) {
                            case LNodeType::EQUAL:
                                r = this->shift_EQUAL();
                                this->push(336, r);
                                break;
                            case LNodeType::IN:
                                r = this->shift_IN();
                                this->push(337, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 309:
                        switch (this->peek->type) {
                            case LNodeType::FBRAC:
                                r = this->shift_FBRAC();
                                this->push(338, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 310:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(126, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 311:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(340, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 312:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 313:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_51();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 314:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(138, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 315:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 316:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(344, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 317:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 318:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 319:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 320:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 321:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_4();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::BStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 322:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 323:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 324:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 325:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(172, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(173, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 326:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(353, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 327:
                        switch (this->peek->type) {
                            case LNodeType::ELSE:
                            case LNodeType::END:
                                r = this->reduce_43();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 328:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->shift_THEN();
                                this->push(355, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 329:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_31();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::IStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 330:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 331:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_46();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::SStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 332:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(357, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 333:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 334:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(112, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(113, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 335:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_4();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::BStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 336:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(155, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(161, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(162, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 337:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 338:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->reduce_54();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Vars), r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(172, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(173, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 339:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->shift_THEN();
                                this->push(363, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 340:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 341:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_46();
                                this->pop(3);
                                this->push(this->GOTO(this->top_state(), LNodeType::SStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 342:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(365, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 343:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_56();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::WStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 344:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 345:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(367, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 346:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_25();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::F1Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 347:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_26();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 348:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(368, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 349:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 350:
                        switch (this->peek->type) {
                            case LNodeType::TO:
                                r = this->shift_TO();
                                this->push(369, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 351:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(370, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 352:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(371, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 353:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(353, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 354:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 355:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 356:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_44();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::RStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 357:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 358:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_57();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::YStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 359:
                        switch (this->peek->type) {
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(376, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 360:
                        switch (this->peek->type) {
                            case LNodeType::TO:
                                r = this->shift_TO();
                                this->push(377, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 361:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(378, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 362:
                        switch (this->peek->type) {
                            case LNodeType::KET:
                                r = this->shift_KET();
                                this->push(379, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 363:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 364:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_44();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::RStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 365:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 366:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_57();
                                this->pop(4);
                                this->push(this->GOTO(this->top_state(), LNodeType::YStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 367:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 368:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 369:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 370:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 371:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 372:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_16();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 373:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 374:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(388, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 375:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 376:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 377:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(163, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(169, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(170, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 378:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 379:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 380:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(244, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(245, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(246, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(248, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(260, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(262, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(263, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 381:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 382:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_24();
                                this->pop(11);
                                this->push(this->GOTO(this->top_state(), LNodeType::F0Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 383:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_17();
                                this->pop(6);
                                this->push(this->GOTO(this->top_state(), LNodeType::EStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 384:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(399, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 385:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 386:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 387:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(402, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 388:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(69, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(75, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(76, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 389:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(404, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 390:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(388, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 391:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(406, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 392:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_17();
                                this->pop(6);
                                this->push(this->GOTO(this->top_state(), LNodeType::EStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 393:
                        switch (this->peek->type) {
                            case LNodeType::DO:
                                r = this->shift_DO();
                                this->push(407, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 394:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 395:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 396:
                        switch (this->peek->type) {
                            case LNodeType::ELSE:
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(244, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(245, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(246, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(248, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(260, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(262, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(263, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 397:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(411, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 398:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(412, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 399:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 400:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(414, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 401:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(415, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 402:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(1, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 403:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(126, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 404:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 405:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_43();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 406:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 407:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 408:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(421, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 409:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(422, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 410:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_43();
                                this->pop(2);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::ELSE:
                                r = this->shift_ELSE();
                                this->push(423, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 411:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 412:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 413:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 414:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 415:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 416:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::EOFF:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_30();
                                this->pop(13);
                                this->push(this->GOTO(this->top_state(), LNodeType::IEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 417:
                        switch (this->peek->type) {
                            case LNodeType::THEN:
                                r = this->shift_THEN();
                                this->push(429, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 418:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_31();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::IStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 419:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_56();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::WStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 420:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 421:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 422:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 423:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(353, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 424:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_31();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::IStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 425:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_56();
                                this->pop(8);
                                this->push(this->GOTO(this->top_state(), LNodeType::WStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 426:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(434, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 427:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_25();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::F1Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 428:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_26();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 429:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 430:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(436, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 431:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_25();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::F1Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 432:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_26();
                                this->pop(9);
                                this->push(this->GOTO(this->top_state(), LNodeType::FCStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 433:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 434:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(322, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 435:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_42();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::NIEStmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(388, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 436:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 437:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->reduce_50();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Stmts), r);
                                break;
                            case LNodeType::BRAC:
                                r = this->shift_BRAC();
                                this->push(5, r);
                                break;
                            case LNodeType::BREAK:
                                r = this->shift_BREAK();
                                this->push(265, r);
                                break;
                            case LNodeType::FOR:
                                r = this->shift_FOR();
                                this->push(266, r);
                                break;
                            case LNodeType::FUNCTION:
                                r = this->shift_FUNCTION();
                                this->push(267, r);
                                break;
                            case LNodeType::IF:
                                r = this->shift_IF();
                                this->push(268, r);
                                break;
                            case LNodeType::RETURN:
                                r = this->shift_RETURN();
                                this->push(279, r);
                                break;
                            case LNodeType::INT:
                                r = this->shift_INT();
                                this->push(30, r);
                                break;
                            case LNodeType::VAR:
                                r = this->shift_VAR();
                                this->push(31, r);
                                break;
                            case LNodeType::WHILE:
                                r = this->shift_WHILE();
                                this->push(284, r);
                                break;
                            case LNodeType::YIELD:
                                r = this->shift_YIELD();
                                this->push(286, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 438:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::ELSE:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_24();
                                this->pop(11);
                                this->push(this->GOTO(this->top_state(), LNodeType::F0Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 439:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_24();
                                this->pop(11);
                                this->push(this->GOTO(this->top_state(), LNodeType::F0Stmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 440:
                        switch (this->peek->type) {
                            case LNodeType::END:
                                r = this->shift_END();
                                this->push(441, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 441:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_15();
                                this->pop(0);
                                this->push(this->GOTO(this->top_state(), LNodeType::Brs), r);
                                break;
                            case LNodeType::BR:
                                r = this->shift_BR();
                                this->push(219, r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    case 442:
                        switch (this->peek->type) {
                            case LNodeType::BRAC:
                            case LNodeType::BREAK:
                            case LNodeType::END:
                            case LNodeType::FOR:
                            case LNodeType::FUNCTION:
                            case LNodeType::IF:
                            case LNodeType::INT:
                            case LNodeType::RETURN:
                            case LNodeType::VAR:
                            case LNodeType::WHILE:
                            case LNodeType::YIELD:
                                r = this->reduce_30();
                                this->pop(13);
                                this->push(this->GOTO(this->top_state(), LNodeType::IEStmt), r);
                                break;
                            default:
                                this->error();
                                break;
                        }
                        break;
                    default:
                        this->error();
                        break;
                }
            }
        } catch (LParserException &exception) {
            std::cout << exception.detail << std::endl;
            return;
        }
    }

    explicit LParser(std::unique_ptr<LLexer> lexer) {
        this->lexer = std::move(lexer);
        this->move();
    }

    // Atom : BRAC Expr KET FCalls
    std::shared_ptr<LNode> reduce_0();

    // Atom : Var FCalls
    std::shared_ptr<LNode> reduce_1();

    // Atoms : 
    std::shared_ptr<LNode> reduce_2();

    // Atoms : Atom Atoms
    std::shared_ptr<LNode> reduce_3();

    // BStmt : BREAK BR Brs
    std::shared_ptr<LNode> reduce_4();

    // BinOP0 : DIV
    std::shared_ptr<LNode> reduce_5();

    // BinOP0 : MUL
    std::shared_ptr<LNode> reduce_6();

    // BinOP1 : ADD
    std::shared_ptr<LNode> reduce_7();

    // BinOP1 : SUB
    std::shared_ptr<LNode> reduce_8();

    // BinOP2 : EQ
    std::shared_ptr<LNode> reduce_9();

    // BinOP2 : G
    std::shared_ptr<LNode> reduce_10();

    // BinOP2 : GEQ
    std::shared_ptr<LNode> reduce_11();

    // BinOP2 : L
    std::shared_ptr<LNode> reduce_12();

    // BinOP2 : LEQ
    std::shared_ptr<LNode> reduce_13();

    // BinOP2 : NEQ
    std::shared_ptr<LNode> reduce_14();

    // Brs : 
    std::shared_ptr<LNode> reduce_15();

    // Brs : BR Brs
    std::shared_ptr<LNode> reduce_16();

    // EStmt : Var Vars EQUAL Expr BR Brs
    std::shared_ptr<LNode> reduce_17();

    // Expr : Expr1
    std::shared_ptr<LNode> reduce_18();

    // Expr : Expr1 BinOP2 Expr
    std::shared_ptr<LNode> reduce_19();

    // Expr0 : Atom
    std::shared_ptr<LNode> reduce_20();

    // Expr0 : Atom BinOP0 Expr0
    std::shared_ptr<LNode> reduce_21();

    // Expr1 : Expr0
    std::shared_ptr<LNode> reduce_22();

    // Expr1 : Expr0 BinOP1 Expr1
    std::shared_ptr<LNode> reduce_23();

    // F0Stmt : FOR Var EQUAL Expr TO Expr DO Brs Stmts END Brs
    std::shared_ptr<LNode> reduce_24();

    // F1Stmt : FOR Var IN Expr DO Brs Stmts END Brs
    std::shared_ptr<LNode> reduce_25();

    // FCStmt : FUNCTION Var FBRAC Vars KET Brs Stmts END Brs
    std::shared_ptr<LNode> reduce_26();

    // FCall : FBRAC Atoms KET
    std::shared_ptr<LNode> reduce_27();

    // FCalls : 
    std::shared_ptr<LNode> reduce_28();

    // FCalls : FCall FCalls
    std::shared_ptr<LNode> reduce_29();

    // IEStmt : IF Expr Brs THEN Brs NIEStmt NIEStmts ELSE Brs Stmt Stmts END Brs
    std::shared_ptr<LNode> reduce_30();

    // IStmt : IF Expr Brs THEN Brs NIEStmts END Brs
    std::shared_ptr<LNode> reduce_31();

    // NIEStmt : BStmt
    std::shared_ptr<LNode> reduce_32();

    // NIEStmt : EStmt
    std::shared_ptr<LNode> reduce_33();

    // NIEStmt : F0Stmt
    std::shared_ptr<LNode> reduce_34();

    // NIEStmt : F1Stmt
    std::shared_ptr<LNode> reduce_35();

    // NIEStmt : FCStmt
    std::shared_ptr<LNode> reduce_36();

    // NIEStmt : IStmt
    std::shared_ptr<LNode> reduce_37();

    // NIEStmt : RStmt
    std::shared_ptr<LNode> reduce_38();

    // NIEStmt : SStmt
    std::shared_ptr<LNode> reduce_39();

    // NIEStmt : WStmt
    std::shared_ptr<LNode> reduce_40();

    // NIEStmt : YStmt
    std::shared_ptr<LNode> reduce_41();

    // NIEStmts : 
    std::shared_ptr<LNode> reduce_42();

    // NIEStmts : NIEStmt NIEStmts
    std::shared_ptr<LNode> reduce_43();

    // RStmt : RETURN Vars BR Brs
    std::shared_ptr<LNode> reduce_44();

    // Root : Start
    std::shared_ptr<LNode> reduce_45();

    // SStmt : Expr BR Brs
    std::shared_ptr<LNode> reduce_46();

    // Start : Brs Stmts
    std::shared_ptr<LNode> reduce_47();

    // Stmt : IEStmt
    std::shared_ptr<LNode> reduce_48();

    // Stmt : NIEStmt
    std::shared_ptr<LNode> reduce_49();

    // Stmts : 
    std::shared_ptr<LNode> reduce_50();

    // Stmts : Stmt Stmts
    std::shared_ptr<LNode> reduce_51();

    // Var : INT
    std::shared_ptr<LNode> reduce_52();

    // Var : VAR
    std::shared_ptr<LNode> reduce_53();

    // Vars : 
    std::shared_ptr<LNode> reduce_54();

    // Vars : Var Vars
    std::shared_ptr<LNode> reduce_55();

    // WStmt : WHILE Expr Brs DO Brs Stmts END Brs
    std::shared_ptr<LNode> reduce_56();

    // YStmt : YIELD Vars BR Brs
    std::shared_ptr<LNode> reduce_57();

    std::shared_ptr<LNode> shift_ADD();

    std::shared_ptr<LNode> shift_BR();

    std::shared_ptr<LNode> shift_BRAC();

    std::shared_ptr<LNode> shift_BREAK();

    std::shared_ptr<LNode> shift_DIV();

    std::shared_ptr<LNode> shift_DO();

    std::shared_ptr<LNode> shift_ELSE();

    std::shared_ptr<LNode> shift_END();

    std::shared_ptr<LNode> shift_EOFF();

    std::shared_ptr<LNode> shift_EQ();

    std::shared_ptr<LNode> shift_EQUAL();

    std::shared_ptr<LNode> shift_FBRAC();

    std::shared_ptr<LNode> shift_FOR();

    std::shared_ptr<LNode> shift_FUNCTION();

    std::shared_ptr<LNode> shift_G();

    std::shared_ptr<LNode> shift_GEQ();

    std::shared_ptr<LNode> shift_IF();

    std::shared_ptr<LNode> shift_IN();

    std::shared_ptr<LNode> shift_INT();

    std::shared_ptr<LNode> shift_KET();

    std::shared_ptr<LNode> shift_L();

    std::shared_ptr<LNode> shift_LEQ();

    std::shared_ptr<LNode> shift_MUL();

    std::shared_ptr<LNode> shift_NEQ();

    std::shared_ptr<LNode> shift_RETURN();

    std::shared_ptr<LNode> shift_SUB();

    std::shared_ptr<LNode> shift_THEN();

    std::shared_ptr<LNode> shift_TO();

    std::shared_ptr<LNode> shift_VAR();

    std::shared_ptr<LNode> shift_WHILE();

    std::shared_ptr<LNode> shift_YIELD();
};

#endif