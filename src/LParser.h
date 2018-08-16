#ifndef LISA_LPARSER_H
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

    std::shared_ptr<LNode> get_node(int i) {
        return this->node_stack[this->node_stack.size() - i];
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
            case 0:
                switch (node_type) {
                    case LNodeType::Start:
                        return 2;
                    case LNodeType::Brs:
                        return 3;
                    default:
                        return -1;
                }
            case 1:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 4;
                    default:
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
                        return -1;
                }
            case 8:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 55;
                    default:
                        return -1;
                }
            case 9:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 58;
                    default:
                        return -1;
                }
            case 10:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 61;
                    default:
                        return -1;
                }
            case 11:
                switch (node_type) {
                    case LNodeType::Var:
                        return 62;
                    default:
                        return -1;
                }
            case 12:
                switch (node_type) {
                    case LNodeType::Var:
                        return 65;
                    default:
                        return -1;
                }
            case 13:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Expr1:
                        return 70;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    case LNodeType::Expr:
                        return 73;
                    default:
                        return -1;
                }
            case 24:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 76;
                    case LNodeType::Var:
                        return 79;
                    default:
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
                        return 81;
                    default:
                        return -1;
                }
            case 32:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Expr1:
                        return 84;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 86;
                    case LNodeType::Expr:
                        return 89;
                    default:
                        return -1;
                }
            case 33:
                switch (node_type) {
                    case LNodeType::Var:
                        return 79;
                    case LNodeType::Vars:
                        return 90;
                    default:
                        return -1;
                }
            case 34:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 91;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 35:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 92;
                    case LNodeType::FCall:
                        return 94;
                    default:
                        return -1;
                }
            case 37:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 96;
                    default:
                        return -1;
                }
            case 38:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 97;
                    default:
                        return -1;
                }
            case 39:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 98;
                    default:
                        return -1;
                }
            case 44:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 103;
                    default:
                        return -1;
                }
            case 45:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::FCalls:
                        return 106;
                    default:
                        return -1;
                }
            case 48:
                switch (node_type) {
                    case LNodeType::Var:
                        return 48;
                    case LNodeType::Vars:
                        return 107;
                    default:
                        return -1;
                }
            case 55:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Expr:
                        return 109;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        return -1;
                }
            case 58:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 112;
                    default:
                        return -1;
                }
            case 61:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Expr1:
                        return 113;
                    default:
                        return -1;
                }
            case 68:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 117;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 69:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 118;
                    case LNodeType::FCall:
                        return 120;
                    default:
                        return -1;
                }
            case 70:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 121;
                    default:
                        return -1;
                }
            case 71:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 122;
                    default:
                        return -1;
                }
            case 72:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 123;
                    default:
                        return -1;
                }
            case 73:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 125;
                    default:
                        return -1;
                }
            case 79:
                switch (node_type) {
                    case LNodeType::Var:
                        return 79;
                    case LNodeType::Vars:
                        return 127;
                    default:
                        return -1;
                }
            case 80:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 128;
                    default:
                        return -1;
                }
            case 82:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 129;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 83:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 130;
                    case LNodeType::FCall:
                        return 132;
                    default:
                        return -1;
                }
            case 84:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 133;
                    default:
                        return -1;
                }
            case 85:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 134;
                    default:
                        return -1;
                }
            case 86:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 135;
                    default:
                        return -1;
                }
            case 89:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 137;
                    default:
                        return -1;
                }
            case 93:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 140;
                    default:
                        return -1;
                }
            case 94:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 94;
                    case LNodeType::FCalls:
                        return 141;
                    default:
                        return -1;
                }
            case 95:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 142;
                    case LNodeType::FCall:
                        return 45;
                    default:
                        return -1;
                }
            case 96:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Expr:
                        return 143;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 97:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 144;
                    default:
                        return -1;
                }
            case 98:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    case LNodeType::Expr1:
                        return 145;
                    default:
                        return -1;
                }
            case 99:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Expr:
                        return 146;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        return -1;
                }
            case 100:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 147;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 101:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 148;
                    case LNodeType::FCall:
                        return 150;
                    default:
                        return -1;
                }
            case 102:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 151;
                    default:
                        return -1;
                }
            case 108:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::FCall:
                        return 45;
                    default:
                        return -1;
                }
            case 114:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Expr1:
                        return 155;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 157;
                    case LNodeType::Expr:
                        return 158;
                    default:
                        return -1;
                }
            case 115:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 166;
                    default:
                        return -1;
                }
            case 116:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 169;
                    case LNodeType::Var:
                        return 172;
                    default:
                        return -1;
                }
            case 119:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 174;
                    default:
                        return -1;
                }
            case 120:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 120;
                    case LNodeType::FCalls:
                        return 175;
                    default:
                        return -1;
                }
            case 121:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Expr1:
                        return 70;
                    case LNodeType::Expr:
                        return 176;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    default:
                        return -1;
                }
            case 122:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 177;
                    default:
                        return -1;
                }
            case 123:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    case LNodeType::Expr1:
                        return 178;
                    default:
                        return -1;
                }
            case 124:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 179;
                    default:
                        return -1;
                }
            case 126:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 181;
                    default:
                        return -1;
                }
            case 131:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 183;
                    default:
                        return -1;
                }
            case 132:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 132;
                    case LNodeType::FCalls:
                        return 184;
                    default:
                        return -1;
                }
            case 133:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Expr1:
                        return 84;
                    case LNodeType::Expr:
                        return 185;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 86;
                    default:
                        return -1;
                }
            case 134:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 186;
                    default:
                        return -1;
                }
            case 135:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 86;
                    case LNodeType::Expr1:
                        return 187;
                    default:
                        return -1;
                }
            case 136:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 188;
                    default:
                        return -1;
                }
            case 138:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 190;
                    default:
                        return -1;
                }
            case 139:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 191;
                    case LNodeType::FCall:
                        return 94;
                    default:
                        return -1;
                }
            case 149:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 195;
                    default:
                        return -1;
                }
            case 150:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 150;
                    case LNodeType::FCalls:
                        return 196;
                    default:
                        return -1;
                }
            case 153:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 197;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 154:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 198;
                    case LNodeType::FCall:
                        return 200;
                    default:
                        return -1;
                }
            case 155:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 201;
                    default:
                        return -1;
                }
            case 156:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 202;
                    default:
                        return -1;
                }
            case 157:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 203;
                    default:
                        return -1;
                }
            case 161:
                switch (node_type) {
                    case LNodeType::Var:
                        return 35;
                    case LNodeType::Expr:
                        return 205;
                    case LNodeType::Expr1:
                        return 37;
                    case LNodeType::Atom:
                        return 38;
                    case LNodeType::Expr0:
                        return 39;
                    default:
                        return -1;
                }
            case 162:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 206;
                    case LNodeType::FCall:
                        return 208;
                    default:
                        return -1;
                }
            case 163:
                switch (node_type) {
                    case LNodeType::BinOP2:
                        return 209;
                    default:
                        return -1;
                }
            case 164:
                switch (node_type) {
                    case LNodeType::BinOP0:
                        return 210;
                    default:
                        return -1;
                }
            case 165:
                switch (node_type) {
                    case LNodeType::BinOP1:
                        return 211;
                    default:
                        return -1;
                }
            case 172:
                switch (node_type) {
                    case LNodeType::Var:
                        return 172;
                    case LNodeType::Vars:
                        return 214;
                    default:
                        return -1;
                }
            case 173:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 215;
                    case LNodeType::FCall:
                        return 120;
                    default:
                        return -1;
                }
            case 180:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 218;
                    default:
                        return -1;
                }
            case 182:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 219;
                    case LNodeType::FCall:
                        return 132;
                    default:
                        return -1;
                }
            case 189:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 221;
                    default:
                        return -1;
                }
            case 193:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 222;
                    default:
                        return -1;
                }
            case 194:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 223;
                    case LNodeType::FCall:
                        return 150;
                    default:
                        return -1;
                }
            case 199:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 226;
                    default:
                        return -1;
                }
            case 200:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 200;
                    case LNodeType::FCalls:
                        return 227;
                    default:
                        return -1;
                }
            case 201:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Expr1:
                        return 155;
                    case LNodeType::Expr:
                        return 228;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 157;
                    default:
                        return -1;
                }
            case 202:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 229;
                    default:
                        return -1;
                }
            case 203:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 157;
                    case LNodeType::Expr1:
                        return 230;
                    default:
                        return -1;
                }
            case 204:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 231;
                    default:
                        return -1;
                }
            case 207:
                switch (node_type) {
                    case LNodeType::Var:
                        return 101;
                    case LNodeType::Atom:
                        return 102;
                    case LNodeType::Atoms:
                        return 233;
                    default:
                        return -1;
                }
            case 208:
                switch (node_type) {
                    case LNodeType::FCall:
                        return 208;
                    case LNodeType::FCalls:
                        return 234;
                    default:
                        return -1;
                }
            case 209:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Expr:
                        return 235;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    default:
                        return -1;
                }
            case 210:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 236;
                    default:
                        return -1;
                }
            case 211:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr1:
                        return 237;
                    default:
                        return -1;
                }
            case 212:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 238;
                    default:
                        return -1;
                }
            case 213:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 239;
                    default:
                        return -1;
                }
            case 217:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 240;
                    default:
                        return -1;
                }
            case 218:
                switch (node_type) {
                    case LNodeType::Var:
                        return 241;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmt:
                        return 245;
                    case LNodeType::NIEStmts:
                        return 247;
                    case LNodeType::BStmt:
                        return 248;
                    case LNodeType::EStmt:
                        return 249;
                    case LNodeType::F0Stmt:
                        return 250;
                    case LNodeType::F1Stmt:
                        return 251;
                    case LNodeType::FCStmt:
                        return 252;
                    case LNodeType::IStmt:
                        return 253;
                    case LNodeType::RStmt:
                        return 254;
                    case LNodeType::SStmt:
                        return 255;
                    case LNodeType::WStmt:
                        return 256;
                    case LNodeType::YStmt:
                        return 257;
                    case LNodeType::Expr:
                        return 259;
                    default:
                        return -1;
                }
            case 221:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    case LNodeType::Stmts:
                        return 283;
                    default:
                        return -1;
                }
            case 225:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 285;
                    case LNodeType::FCall:
                        return 200;
                    default:
                        return -1;
                }
            case 232:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 288;
                    case LNodeType::FCall:
                        return 208;
                    default:
                        return -1;
                }
            case 238:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 290;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 239:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 291;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 241:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::Vars:
                        return 292;
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::Var:
                        return 48;
                    default:
                        return -1;
                }
            case 243:
                switch (node_type) {
                    case LNodeType::Var:
                        return 293;
                    default:
                        return -1;
                }
            case 244:
                switch (node_type) {
                    case LNodeType::Var:
                        return 294;
                    default:
                        return -1;
                }
            case 245:
                switch (node_type) {
                    case LNodeType::Var:
                        return 241;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 295;
                    case LNodeType::BStmt:
                        return 248;
                    case LNodeType::EStmt:
                        return 249;
                    case LNodeType::F0Stmt:
                        return 250;
                    case LNodeType::F1Stmt:
                        return 251;
                    case LNodeType::FCStmt:
                        return 252;
                    case LNodeType::IStmt:
                        return 253;
                    case LNodeType::RStmt:
                        return 254;
                    case LNodeType::SStmt:
                        return 255;
                    case LNodeType::WStmt:
                        return 256;
                    case LNodeType::YStmt:
                        return 257;
                    case LNodeType::NIEStmt:
                        return 296;
                    case LNodeType::Expr:
                        return 259;
                    default:
                        return -1;
                }
            case 246:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Expr1:
                        return 70;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    case LNodeType::Expr:
                        return 297;
                    default:
                        return -1;
                }
            case 258:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 299;
                    case LNodeType::Var:
                        return 79;
                    default:
                        return -1;
                }
            case 260:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Expr1:
                        return 84;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 86;
                    case LNodeType::Expr:
                        return 301;
                    default:
                        return -1;
                }
            case 261:
                switch (node_type) {
                    case LNodeType::Var:
                        return 79;
                    case LNodeType::Vars:
                        return 302;
                    default:
                        return -1;
                }
            case 262:
                switch (node_type) {
                    case LNodeType::FCalls:
                        return 42;
                    case LNodeType::Vars:
                        return 303;
                    case LNodeType::FCall:
                        return 45;
                    case LNodeType::Var:
                        return 48;
                    default:
                        return -1;
                }
            case 264:
                switch (node_type) {
                    case LNodeType::Var:
                        return 304;
                    default:
                        return -1;
                }
            case 265:
                switch (node_type) {
                    case LNodeType::Var:
                        return 305;
                    default:
                        return -1;
                }
            case 266:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Expr1:
                        return 70;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    case LNodeType::Expr:
                        return 306;
                    default:
                        return -1;
                }
            case 277:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 307;
                    case LNodeType::Var:
                        return 79;
                    default:
                        return -1;
                }
            case 281:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    case LNodeType::Stmts:
                        return 309;
                    default:
                        return -1;
                }
            case 282:
                switch (node_type) {
                    case LNodeType::Var:
                        return 83;
                    case LNodeType::Expr1:
                        return 84;
                    case LNodeType::Atom:
                        return 85;
                    case LNodeType::Expr0:
                        return 86;
                    case LNodeType::Expr:
                        return 310;
                    default:
                        return -1;
                }
            case 284:
                switch (node_type) {
                    case LNodeType::Var:
                        return 79;
                    case LNodeType::Vars:
                        return 312;
                    default:
                        return -1;
                }
            case 287:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 313;
                    default:
                        return -1;
                }
            case 296:
                switch (node_type) {
                    case LNodeType::Var:
                        return 241;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 248;
                    case LNodeType::EStmt:
                        return 249;
                    case LNodeType::F0Stmt:
                        return 250;
                    case LNodeType::F1Stmt:
                        return 251;
                    case LNodeType::FCStmt:
                        return 252;
                    case LNodeType::IStmt:
                        return 253;
                    case LNodeType::RStmt:
                        return 254;
                    case LNodeType::SStmt:
                        return 255;
                    case LNodeType::WStmt:
                        return 256;
                    case LNodeType::YStmt:
                        return 257;
                    case LNodeType::NIEStmt:
                        return 296;
                    case LNodeType::NIEStmts:
                        return 321;
                    case LNodeType::Expr:
                        return 259;
                    default:
                        return -1;
                }
            case 297:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 322;
                    default:
                        return -1;
                }
            case 298:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 323;
                    default:
                        return -1;
                }
            case 300:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 326;
                    default:
                        return -1;
                }
            case 301:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 327;
                    default:
                        return -1;
                }
            case 306:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 333;
                    default:
                        return -1;
                }
            case 308:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 335;
                    default:
                        return -1;
                }
            case 310:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 336;
                    default:
                        return -1;
                }
            case 311:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 337;
                    default:
                        return -1;
                }
            case 313:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 339;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 314:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 340;
                    default:
                        return -1;
                }
            case 315:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 341;
                    default:
                        return -1;
                }
            case 316:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Expr:
                        return 342;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        return -1;
                }
            case 317:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Expr1:
                        return 155;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 157;
                    case LNodeType::Expr:
                        return 343;
                    default:
                        return -1;
                }
            case 318:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 344;
                    default:
                        return -1;
                }
            case 319:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 345;
                    case LNodeType::Var:
                        return 172;
                    default:
                        return -1;
                }
            case 320:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 347;
                    default:
                        return -1;
                }
            case 324:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 349;
                    default:
                        return -1;
                }
            case 325:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 350;
                    default:
                        return -1;
                }
            case 328:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 352;
                    default:
                        return -1;
                }
            case 329:
                switch (node_type) {
                    case LNodeType::Var:
                        return 108;
                    case LNodeType::Expr:
                        return 353;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    default:
                        return -1;
                }
            case 330:
                switch (node_type) {
                    case LNodeType::Var:
                        return 154;
                    case LNodeType::Expr1:
                        return 155;
                    case LNodeType::Atom:
                        return 156;
                    case LNodeType::Expr0:
                        return 157;
                    case LNodeType::Expr:
                        return 354;
                    default:
                        return -1;
                }
            case 331:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 355;
                    default:
                        return -1;
                }
            case 332:
                switch (node_type) {
                    case LNodeType::Vars:
                        return 356;
                    case LNodeType::Var:
                        return 172;
                    default:
                        return -1;
                }
            case 334:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 358;
                    default:
                        return -1;
                }
            case 338:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 360;
                    default:
                        return -1;
                }
            case 346:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 366;
                    default:
                        return -1;
                }
            case 347:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmt:
                        return 367;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    default:
                        return -1;
                }
            case 348:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 368;
                    default:
                        return -1;
                }
            case 351:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 369;
                    default:
                        return -1;
                }
            case 357:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 374;
                    default:
                        return -1;
                }
            case 359:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 375;
                    default:
                        return -1;
                }
            case 361:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 376;
                    default:
                        return -1;
                }
            case 362:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 377;
                    default:
                        return -1;
                }
            case 363:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 378;
                    default:
                        return -1;
                }
            case 364:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 379;
                    default:
                        return -1;
                }
            case 365:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 380;
                    default:
                        return -1;
                }
            case 367:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 381;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 368:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 383;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::NIEStmt:
                        return 384;
                    case LNodeType::Expr:
                        return 278;
                    default:
                        return -1;
                }
            case 369:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    case LNodeType::Stmts:
                        return 385;
                    default:
                        return -1;
                }
            case 370:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 386;
                    default:
                        return -1;
                }
            case 371:
                switch (node_type) {
                    case LNodeType::Var:
                        return 162;
                    case LNodeType::Expr1:
                        return 163;
                    case LNodeType::Atom:
                        return 164;
                    case LNodeType::Expr0:
                        return 165;
                    case LNodeType::Expr:
                        return 387;
                    default:
                        return -1;
                }
            case 372:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 388;
                    default:
                        return -1;
                }
            case 373:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 389;
                    default:
                        return -1;
                }
            case 374:
                switch (node_type) {
                    case LNodeType::Var:
                        return 241;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmt:
                        return 390;
                    case LNodeType::NIEStmts:
                        return 391;
                    case LNodeType::BStmt:
                        return 248;
                    case LNodeType::EStmt:
                        return 249;
                    case LNodeType::F0Stmt:
                        return 250;
                    case LNodeType::F1Stmt:
                        return 251;
                    case LNodeType::FCStmt:
                        return 252;
                    case LNodeType::IStmt:
                        return 253;
                    case LNodeType::RStmt:
                        return 254;
                    case LNodeType::SStmt:
                        return 255;
                    case LNodeType::WStmt:
                        return 256;
                    case LNodeType::YStmt:
                        return 257;
                    case LNodeType::Expr:
                        return 259;
                    default:
                        return -1;
                }
            case 375:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    case LNodeType::Stmts:
                        return 392;
                    default:
                        return -1;
                }
            case 379:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 394;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 380:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 395;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 382:
                switch (node_type) {
                    case LNodeType::Var:
                        return 69;
                    case LNodeType::Expr1:
                        return 70;
                    case LNodeType::Atom:
                        return 71;
                    case LNodeType::Expr0:
                        return 72;
                    case LNodeType::Expr:
                        return 397;
                    default:
                        return -1;
                }
            case 384:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::NIEStmt:
                        return 384;
                    case LNodeType::NIEStmts:
                        return 399;
                    case LNodeType::Expr:
                        return 278;
                    default:
                        return -1;
                }
            case 388:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 402;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 389:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 403;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 390:
                switch (node_type) {
                    case LNodeType::Var:
                        return 241;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 404;
                    case LNodeType::BStmt:
                        return 248;
                    case LNodeType::EStmt:
                        return 249;
                    case LNodeType::F0Stmt:
                        return 250;
                    case LNodeType::F1Stmt:
                        return 251;
                    case LNodeType::FCStmt:
                        return 252;
                    case LNodeType::IStmt:
                        return 253;
                    case LNodeType::RStmt:
                        return 254;
                    case LNodeType::SStmt:
                        return 255;
                    case LNodeType::WStmt:
                        return 256;
                    case LNodeType::YStmt:
                        return 257;
                    case LNodeType::NIEStmt:
                        return 296;
                    case LNodeType::Expr:
                        return 259;
                    default:
                        return -1;
                }
            case 393:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 407;
                    default:
                        return -1;
                }
            case 396:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 410;
                    default:
                        return -1;
                }
            case 397:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 411;
                    default:
                        return -1;
                }
            case 398:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 412;
                    default:
                        return -1;
                }
            case 400:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 413;
                    default:
                        return -1;
                }
            case 401:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 414;
                    default:
                        return -1;
                }
            case 405:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 418;
                    default:
                        return -1;
                }
            case 406:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 419;
                    default:
                        return -1;
                }
            case 407:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 420;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 408:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 421;
                    default:
                        return -1;
                }
            case 409:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 422;
                    default:
                        return -1;
                }
            case 414:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 424;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 415:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 425;
                    default:
                        return -1;
                }
            case 416:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 426;
                    default:
                        return -1;
                }
            case 417:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 427;
                    default:
                        return -1;
                }
            case 423:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 429;
                    default:
                        return -1;
                }
            case 427:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmt:
                        return 431;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    default:
                        return -1;
                }
            case 428:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 432;
                    default:
                        return -1;
                }
            case 429:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::NIEStmts:
                        return 391;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::NIEStmt:
                        return 384;
                    case LNodeType::Expr:
                        return 278;
                    default:
                        return -1;
                }
            case 430:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 433;
                    default:
                        return -1;
                }
            case 431:
                switch (node_type) {
                    case LNodeType::Var:
                        return 262;
                    case LNodeType::Expr1:
                        return 8;
                    case LNodeType::Atom:
                        return 9;
                    case LNodeType::Expr0:
                        return 10;
                    case LNodeType::Stmts:
                        return 434;
                    case LNodeType::BStmt:
                        return 267;
                    case LNodeType::EStmt:
                        return 268;
                    case LNodeType::F0Stmt:
                        return 269;
                    case LNodeType::F1Stmt:
                        return 270;
                    case LNodeType::FCStmt:
                        return 271;
                    case LNodeType::IStmt:
                        return 272;
                    case LNodeType::RStmt:
                        return 273;
                    case LNodeType::SStmt:
                        return 274;
                    case LNodeType::WStmt:
                        return 275;
                    case LNodeType::YStmt:
                        return 276;
                    case LNodeType::Expr:
                        return 278;
                    case LNodeType::IEStmt:
                        return 279;
                    case LNodeType::NIEStmt:
                        return 280;
                    case LNodeType::Stmt:
                        return 281;
                    default:
                        return -1;
                }
            case 435:
                switch (node_type) {
                    case LNodeType::Brs:
                        return 436;
                    default:
                        return -1;
                }
            default:
                return -1;
        }
    }

    int top_state() {
        return this->state_stack[this->node_stack.size() - 1];
    }

    void parse() {
        this->push(0, nullptr);
        std::shared_ptr<LNode> r;
        int flag = -1;
        while (!this->terminated) {
            switch (this->top_state()) {
                case 0:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 1:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 2:
                    switch (this->peek.type) {
                        case LNodeType::EOFF:
                            r = this->reduce_45();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Root);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 3:
                    switch (this->peek.type) {
                        case LNodeType::EOFF:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(7, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(11, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(12, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(13, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(24, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(32, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(33, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 4:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 5:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 6:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQUAL:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(46, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(47, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 7:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 8:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 9:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 10:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 11:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(63, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(64, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 12:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(66, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(67, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 13:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 14:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 15:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 16:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 17:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 18:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 19:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 20:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 21:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 22:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 23:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 24:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 25:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(80, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 26:
                    switch (this->peek.type) {
                        case LNodeType::EOFF:
                            r = this->reduce_47();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Start);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 27:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 28:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 29:
                    switch (this->peek.type) {
                        case LNodeType::EOFF:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(7, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(11, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(12, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(13, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(24, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(32, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(33, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 30:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 31:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 32:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 33:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 34:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 35:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(93, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 36:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(95, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 37:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 38:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 39:
                    switch (this->peek.type) {
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::KET:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 40:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 41:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 42:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 43:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(99, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 44:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 45:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 46:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 47:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 48:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(46, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(47, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 49:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_9();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 50:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_10();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 51:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_11();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 52:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_12();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 53:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_13();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 54:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_14();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP2);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 55:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 56:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_5();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 57:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_6();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 58:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 59:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_7();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 60:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_8();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BinOP1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 61:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 62:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(114, r);
                            break;
                        case LNodeType::IN:
                            r = this->shift_IN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(115, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 63:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                        case LNodeType::IN:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 64:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                        case LNodeType::IN:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 65:
                    switch (this->peek.type) {
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(116, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 66:
                    switch (this->peek.type) {
                        case LNodeType::FBRAC:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 67:
                    switch (this->peek.type) {
                        case LNodeType::FBRAC:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 68:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 69:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(119, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 70:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::THEN:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 71:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 72:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                        case LNodeType::THEN:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 73:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(124, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 74:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 75:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 76:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(126, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 77:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 78:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::INT:
                        case LNodeType::VAR:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 79:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 80:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 81:
                    switch (this->peek.type) {
                        case LNodeType::EOFF:
                            r = this->reduce_51();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 82:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 83:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(131, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 84:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::DO:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 85:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 86:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::DO:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 87:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 88:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 89:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(136, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 90:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(138, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 91:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(139, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 92:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 93:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 94:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(93, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 95:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 96:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 97:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 98:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 99:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 100:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 101:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_28();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(149, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 102:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 103:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(152, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 104:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::FBRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 105:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::FBRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 106:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 107:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->reduce_55();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 108:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 109:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 110:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 111:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 112:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 113:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 114:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 115:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 116:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(170, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(171, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 117:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(173, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 118:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 119:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 120:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(119, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 121:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 122:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 123:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 124:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(124, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 125:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->shift_THEN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(180, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 126:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 127:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_55();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 128:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::SStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 129:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(182, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 130:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 131:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 132:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(131, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 133:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 134:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 135:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 136:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(136, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 137:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(189, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 138:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 139:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(93, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 140:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(192, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 141:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 142:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 143:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 144:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 145:
                    switch (this->peek.type) {
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::KET:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 146:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(193, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 147:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(194, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 148:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_1();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 149:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 150:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_28();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(149, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 151:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_3();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 152:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 153:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 154:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(199, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 155:
                    switch (this->peek.type) {
                        case LNodeType::TO:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 156:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 157:
                    switch (this->peek.type) {
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                        case LNodeType::TO:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 158:
                    switch (this->peek.type) {
                        case LNodeType::TO:
                            r = this->shift_TO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(204, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 159:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 160:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 161:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(34, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(40, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(41, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 162:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(207, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 163:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_18();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQ:
                            r = this->shift_EQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(49, r);
                            break;
                        case LNodeType::G:
                            r = this->shift_G();
                            if (this->terminated) {
                                break;
                            }
                            this->push(50, r);
                            break;
                        case LNodeType::GEQ:
                            r = this->shift_GEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(51, r);
                            break;
                        case LNodeType::L:
                            r = this->shift_L();
                            if (this->terminated) {
                                break;
                            }
                            this->push(52, r);
                            break;
                        case LNodeType::LEQ:
                            r = this->shift_LEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(53, r);
                            break;
                        case LNodeType::NEQ:
                            r = this->shift_NEQ();
                            if (this->terminated) {
                                break;
                            }
                            this->push(54, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 164:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::DIV:
                            r = this->shift_DIV();
                            if (this->terminated) {
                                break;
                            }
                            this->push(56, r);
                            break;
                        case LNodeType::MUL:
                            r = this->shift_MUL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(57, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 165:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_22();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ADD:
                            r = this->shift_ADD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(59, r);
                            break;
                        case LNodeType::SUB:
                            r = this->shift_SUB();
                            if (this->terminated) {
                                break;
                            }
                            this->push(60, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 166:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(212, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 167:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 168:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 169:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(213, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 170:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_52();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 171:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_53();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Var);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 172:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(170, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(171, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 173:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(119, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 174:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(216, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 175:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 176:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::THEN:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 177:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 178:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                        case LNodeType::THEN:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 179:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_16();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 180:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 181:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::RStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 182:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(131, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 183:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(220, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 184:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 185:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::DO:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 186:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 187:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                        case LNodeType::DO:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 188:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_16();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 189:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 190:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::YStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 191:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 192:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 193:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 194:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_28();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(149, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 195:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(224, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 196:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_29();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 197:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(225, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 198:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 199:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 200:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(199, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 201:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 202:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 203:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 204:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 205:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(232, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 206:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 207:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_2();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Atoms);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(100, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(104, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(105, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 208:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(207, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 209:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 210:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 211:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 212:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 213:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 214:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_55();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 215:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 216:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 217:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 218:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(242, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(243, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(244, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(246, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(258, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(260, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(261, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 219:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 220:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 221:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 222:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(6);
                            flag = this->GOTO(this->top_state(), LNodeType::EStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 223:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_0();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 224:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                        case LNodeType::FBRAC:
                        case LNodeType::INT:
                        case LNodeType::KET:
                        case LNodeType::VAR:
                            r = this->reduce_27();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 225:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(199, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 226:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(286, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 227:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 228:
                    switch (this->peek.type) {
                        case LNodeType::TO:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 229:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 230:
                    switch (this->peek.type) {
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                        case LNodeType::TO:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 231:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(287, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 232:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(207, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 233:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(289, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 234:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 235:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_19();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 236:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr0);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 237:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                        case LNodeType::EQ:
                        case LNodeType::G:
                        case LNodeType::GEQ:
                        case LNodeType::L:
                        case LNodeType::LEQ:
                        case LNodeType::NEQ:
                            r = this->reduce_23();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::Expr1);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 238:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 239:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 240:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 241:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQUAL:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(46, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(47, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 242:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 243:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(63, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(64, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 244:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(66, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(67, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 245:
                    switch (this->peek.type) {
                        case LNodeType::ELSE:
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(242, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(243, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(244, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(246, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(258, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(260, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(261, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 246:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 247:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(298, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 248:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 249:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 250:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 251:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 252:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 253:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 254:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 255:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 256:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 257:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 258:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 259:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(300, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 260:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 261:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 262:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::FCalls);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::EQUAL:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(44, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(46, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(47, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 263:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::BStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 264:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(63, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(64, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 265:
                    switch (this->peek.type) {
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(66, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(67, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 266:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 267:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 268:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 269:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 270:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 271:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 272:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 273:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 274:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 275:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 276:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 277:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 278:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(308, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 279:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 280:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(1);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 281:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 282:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(82, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(87, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(88, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 283:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(311, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 284:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(77, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(78, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 285:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 286:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 287:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 288:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::Atom);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 289:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::FCall);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 290:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(314, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 291:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(315, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 292:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(316, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 293:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(317, r);
                            break;
                        case LNodeType::IN:
                            r = this->shift_IN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(318, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 294:
                    switch (this->peek.type) {
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(319, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 295:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_43();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ELSE:
                            r = this->shift_ELSE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(320, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 296:
                    switch (this->peek.type) {
                        case LNodeType::ELSE:
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(242, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(243, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(244, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(246, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(258, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(260, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(261, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 297:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(124, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 298:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 299:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(324, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 300:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 301:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(136, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 302:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(328, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 303:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(329, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 304:
                    switch (this->peek.type) {
                        case LNodeType::EQUAL:
                            r = this->shift_EQUAL();
                            if (this->terminated) {
                                break;
                            }
                            this->push(330, r);
                            break;
                        case LNodeType::IN:
                            r = this->shift_IN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(331, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 305:
                    switch (this->peek.type) {
                        case LNodeType::FBRAC:
                            r = this->shift_FBRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(332, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 306:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(124, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 307:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(334, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 308:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 309:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_51();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 310:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(136, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 311:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 312:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(338, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 313:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 314:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 315:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 316:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 317:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 318:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 319:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(170, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(171, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 320:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(346, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 321:
                    switch (this->peek.type) {
                        case LNodeType::ELSE:
                        case LNodeType::END:
                            r = this->reduce_43();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 322:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->shift_THEN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(348, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 323:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::IStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 324:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 325:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 326:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::SStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 327:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(351, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 328:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 329:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(110, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(111, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 330:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(153, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(159, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(160, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 331:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 332:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->reduce_54();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Vars);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(170, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(171, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 333:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->shift_THEN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(357, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 334:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 335:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(3);
                            flag = this->GOTO(this->top_state(), LNodeType::SStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 336:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(359, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 337:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::WStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 338:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 339:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(361, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 340:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::F1Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 341:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::FCStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 342:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(362, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 343:
                    switch (this->peek.type) {
                        case LNodeType::TO:
                            r = this->shift_TO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(363, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 344:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(364, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 345:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(365, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 346:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(346, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 347:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 348:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 349:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::RStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 350:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 351:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 352:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::YStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 353:
                    switch (this->peek.type) {
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(370, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 354:
                    switch (this->peek.type) {
                        case LNodeType::TO:
                            r = this->shift_TO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(371, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 355:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(372, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 356:
                    switch (this->peek.type) {
                        case LNodeType::KET:
                            r = this->shift_KET();
                            if (this->terminated) {
                                break;
                            }
                            this->push(373, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 357:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 358:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::RStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 359:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 360:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(4);
                            flag = this->GOTO(this->top_state(), LNodeType::YStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 361:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 362:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 363:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 364:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 365:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 366:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 367:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 368:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(382, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 369:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 370:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 371:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(161, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(167, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(168, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 372:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 373:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 374:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(242, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(243, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(244, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(246, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(258, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(260, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(261, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 375:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 376:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(11);
                            flag = this->GOTO(this->top_state(), LNodeType::F0Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 377:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(6);
                            flag = this->GOTO(this->top_state(), LNodeType::EStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 378:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(393, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 379:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 380:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 381:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(396, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 382:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(68, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(74, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(75, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 383:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(398, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 384:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(382, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 385:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(400, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 386:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(6);
                            flag = this->GOTO(this->top_state(), LNodeType::EStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 387:
                    switch (this->peek.type) {
                        case LNodeType::DO:
                            r = this->shift_DO();
                            if (this->terminated) {
                                break;
                            }
                            this->push(401, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 388:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 389:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 390:
                    switch (this->peek.type) {
                        case LNodeType::ELSE:
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(242, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(243, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(244, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(246, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(258, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(260, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(261, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 391:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(405, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 392:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(406, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 393:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 394:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(408, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 395:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(409, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 396:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(1, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 397:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->reduce_15();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(124, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 398:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 399:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_43();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 400:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 401:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 402:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(415, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 403:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(416, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 404:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_43();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(2);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::ELSE:
                            r = this->shift_ELSE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(417, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 405:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 406:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 407:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 408:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 409:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 410:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(13);
                            flag = this->GOTO(this->top_state(), LNodeType::IEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 411:
                    switch (this->peek.type) {
                        case LNodeType::THEN:
                            r = this->shift_THEN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(423, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 412:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::IStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 413:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::WStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 414:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 415:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 416:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 417:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(346, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 418:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::IStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 419:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(8);
                            flag = this->GOTO(this->top_state(), LNodeType::WStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 420:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(428, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 421:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::F1Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 422:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::FCStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 423:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 424:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(430, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 425:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::F1Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 426:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(9);
                            flag = this->GOTO(this->top_state(), LNodeType::FCStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 427:
                    switch (this->peek.type) {
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 428:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(325, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 429:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_42();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::NIEStmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(382, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 430:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 431:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->reduce_50();
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Stmts);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BRAC:
                            r = this->shift_BRAC();
                            if (this->terminated) {
                                break;
                            }
                            this->push(5, r);
                            break;
                        case LNodeType::BREAK:
                            r = this->shift_BREAK();
                            if (this->terminated) {
                                break;
                            }
                            this->push(263, r);
                            break;
                        case LNodeType::FOR:
                            r = this->shift_FOR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(264, r);
                            break;
                        case LNodeType::FUNCTION:
                            r = this->shift_FUNCTION();
                            if (this->terminated) {
                                break;
                            }
                            this->push(265, r);
                            break;
                        case LNodeType::IF:
                            r = this->shift_IF();
                            if (this->terminated) {
                                break;
                            }
                            this->push(266, r);
                            break;
                        case LNodeType::RETURN:
                            r = this->shift_RETURN();
                            if (this->terminated) {
                                break;
                            }
                            this->push(277, r);
                            break;
                        case LNodeType::INT:
                            r = this->shift_INT();
                            if (this->terminated) {
                                break;
                            }
                            this->push(30, r);
                            break;
                        case LNodeType::VAR:
                            r = this->shift_VAR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(31, r);
                            break;
                        case LNodeType::WHILE:
                            r = this->shift_WHILE();
                            if (this->terminated) {
                                break;
                            }
                            this->push(282, r);
                            break;
                        case LNodeType::YIELD:
                            r = this->shift_YIELD();
                            if (this->terminated) {
                                break;
                            }
                            this->push(284, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 432:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(11);
                            flag = this->GOTO(this->top_state(), LNodeType::F0Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 433:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(11);
                            flag = this->GOTO(this->top_state(), LNodeType::F0Stmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 434:
                    switch (this->peek.type) {
                        case LNodeType::END:
                            r = this->shift_END();
                            if (this->terminated) {
                                break;
                            }
                            this->push(435, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 435:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(0);
                            flag = this->GOTO(this->top_state(), LNodeType::Brs);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
                            break;
                        case LNodeType::BR:
                            r = this->shift_BR();
                            if (this->terminated) {
                                break;
                            }
                            this->push(217, r);
                            break;
                        default:
                            this->error();
                            break;
                    }
                    break;
                case 436:
                    switch (this->peek.type) {
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
                            if (this->terminated) {
                                break;
                            }
                            this->pop(13);
                            flag = this->GOTO(this->top_state(), LNodeType::IEStmt);
                            if (flag < 0) {
                                this->error();
                                break;
                            }
                            this->push(flag, r);
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

    // BStmt : BREAK
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