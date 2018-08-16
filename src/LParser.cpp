#include <utility>

#include "LParser.h"

#include <sstream>
#include <vector>

class LNodeChildren {
public:
    std::vector<std::shared_ptr<LNode>> children;

    LNodeChildren() = default;
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

std::optional<std::shared_ptr<LNode>> LParser::reduce_0() {
    // Atom : BRAC Expr KET FCalls
    auto expr = this->get_node(3);
    auto fcalls = this->get_node(1);
    auto atom = std::make_shared<LNodeData<LNodeAtom>>(LNodeType::Atom, LNodeAtom(expr, fcalls));
    return std::static_pointer_cast<LNode>(atom);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_1() {
    // Atom : Var FCalls
    auto var = this->get_node(2);
    auto fcalls = this->get_node(1);
    auto atom = std::make_shared<LNodeData<LNodeAtom>>(LNodeType::Atom, LNodeAtom(var, fcalls));
    return std::static_pointer_cast<LNode>(atom);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_2() {
    // Atoms : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::Atoms, LNodeChildren());
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_3() {
    // Atoms : Atom Atoms
    auto atom = this->get_node(2);
    auto atoms = this->get_node(1);
    lnode_get<LNodeChildren>(atoms)->value.children.push_back(atom);
    return atoms;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_4() {
    // BStmt : BREAK
    return std::make_shared<LNode>(LNodeType::BStmt);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_5() {
    // BinOP0 : DIV
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_6() {
    // BinOP0 : MUL
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_7() {
    // BinOP1 : ADD
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_8() {
    // BinOP1 : SUB
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_9() {
    // BinOP2 : EQ
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_10() {
    // BinOP2 : G
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_11() {
    // BinOP2 : GEQ
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_12() {
    // BinOP2 : L
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_13() {
    // BinOP2 : LEQ
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_14() {
    // BinOP2 : NEQ
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_15() {
    // Brs : 
    return std::make_shared<LNode>(LNodeType::Brs);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_16() {
    // Brs : BR Brs
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_17() { // TODO
    // EStmt : Var Vars EQUAL Expr BR Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_18() { // TODO
    // Expr : Expr1
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_19() {
    // Expr : Expr1 BinOP2 Expr
    auto expr1 = this->get_node(3);
    auto op = this->get_node(2);
    auto expr = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, expr1, expr));
    return r;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_20() {
    // Expr0 : Atom
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_21() {
    // Expr0 : Atom BinOP0 Expr0
    auto atom = this->get_node(3);
    auto op = this->get_node(2);
    auto expr0 = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, atom, expr0));
    return r;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_22() {
    // Expr1 : Expr0
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_23() {
    // Expr1 : Expr0 BinOP1 Expr1
    auto atom = this->get_node(3);
    auto op = this->get_node(2);
    auto expr1 = this->get_node(1);
    auto r = std::make_shared<LNodeData<LNodeExpr>>(LNodeType::Expr, LNodeExpr(op, atom, expr1));
    return r;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_24() { // TODO
    // F0Stmt : FOR Var EQUAL Expr TO Expr DO Brs Stmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_25() { // TODO
    // F1Stmt : FOR Var IN Expr DO Brs Stmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_26() { // TODO
    // FCStmt : FUNCTION Var FBRAC Vars KET Brs Stmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_27() { // TODO
    // FCall : FBRAC Atoms KET
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_28() { // TODO
    // FCalls : 
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_29() { // TODO
    // FCalls : FCall FCalls
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_30() { // TODO
    // IEStmt : IF Expr Brs THEN Brs NIEStmt NIEStmts ELSE Brs Stmt Stmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_31() { // TODO
    // IStmt : IF Expr Brs THEN Brs NIEStmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_32() { // TODO
    // NIEStmt : BStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_33() { // TODO
    // NIEStmt : EStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_34() { // TODO
    // NIEStmt : F0Stmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_35() { // TODO
    // NIEStmt : F1Stmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_36() { // TODO
    // NIEStmt : FCStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_37() { // TODO
    // NIEStmt : IStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_38() { // TODO
    // NIEStmt : RStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_39() { // TODO
    // NIEStmt : SStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_40() { // TODO
    // NIEStmt : WStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_41() { // TODO
    // NIEStmt : YStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_42() { // TODO
    // NIEStmts : 
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_43() { // TODO
    // NIEStmts : NIEStmt NIEStmts
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_44() { // TODO
    // RStmt : RETURN Vars BR Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_45() { // TODO
    // Root : Start
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_46() { // TODO
    // SStmt : Expr BR Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_47() { // TODO
    // Start : Brs Stmts
    this->accept();
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_48() { // TODO
    // Stmt : IEStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_49() { // TODO
    // Stmt : NIEStmt
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_50() { // TODO
    // Stmts : 
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_51() { // TODO
    // Stmts : Stmt Stmts
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_52() {
    // Var : INT
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_53() {
    // Var : VAR
    return this->get_node(1);
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_54() {
    // Vars : 
    return std::make_shared<LNodeData<LNodeChildren>>(LNodeType::Vars, LNodeChildren());
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_55() {
    // Vars : Var Vars
    auto var = this->get_node(2);
    auto vars = this->get_node(1);
    lnode_get<LNodeChildren>(vars)->value.children.push_back(var);
    return vars;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_56() { // TODO
    // WStmt : WHILE Expr Brs DO Brs Stmts END Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_57() { // TODO
    // YStmt : YIELD Vars BR Brs
    return nullptr;
}

std::optional<std::shared_ptr<LNode>> LParser::shift_ADD() {
    this->move();
    return std::make_shared<LNode>(LNodeType::ADD);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BR() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BR);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BRAC() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BRAC);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BREAK() {
    this->move();
    return std::make_shared<LNode>(LNodeType::BREAK);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_DIV() {
    this->move();
    return std::make_shared<LNode>(LNodeType::DIV);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_DO() {
    this->move();
    return std::make_shared<LNode>(LNodeType::DO);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_ELSE() {
    this->move();
    return std::make_shared<LNode>(LNodeType::ELSE);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_END() {
    this->move();
    return std::make_shared<LNode>(LNodeType::END);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EOFF() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EOFF);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EQ);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EQUAL() {
    this->move();
    return std::make_shared<LNode>(LNodeType::EQUAL);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FBRAC() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FBRAC);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FOR() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FOR);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FUNCTION() {
    this->move();
    return std::make_shared<LNode>(LNodeType::FUNCTION);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_G() {
    this->move();
    return std::make_shared<LNode>(LNodeType::G);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_GEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::GEQ);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_IF() {
    this->move();
    return std::make_shared<LNode>(LNodeType::IF);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_IN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::IN);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_INT() {
    auto r = std::make_shared<LNodeData<int64_t>>(LNodeType::INT, std::stol(this->peek.token));
    this->move();
    return r;
}

std::optional<std::shared_ptr<LNode>> LParser::shift_KET() {
    this->move();
    return std::make_shared<LNode>(LNodeType::KET);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_L() {
    this->move();
    return std::make_shared<LNode>(LNodeType::L);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_LEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::LEQ);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_MUL() {
    this->move();
    return std::make_shared<LNode>(LNodeType::MUL);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_NEQ() {
    this->move();
    return std::make_shared<LNode>(LNodeType::NEQ);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_RETURN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::RETURN);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_SUB() {
    this->move();
    return std::make_shared<LNode>(LNodeType::SUB);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_THEN() {
    this->move();
    return std::make_shared<LNode>(LNodeType::THEN);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_TO() {
    this->move();
    return std::make_shared<LNode>(LNodeType::TO);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_VAR() {
    auto r = std::make_shared<LNodeData<std::string>>(LNodeType::VAR, this->peek.token);
    this->move();
    return r;
}

std::optional<std::shared_ptr<LNode>> LParser::shift_WHILE() {
    this->move();
    return std::make_shared<LNode>(LNodeType::WHILE);
}

std::optional<std::shared_ptr<LNode>> LParser::shift_YIELD() {
    this->move();
    return std::make_shared<LNode>(LNodeType::YIELD);
}
