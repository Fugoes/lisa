#include "LParser.h"


std::optional<std::shared_ptr<LNode>> LParser::reduce_0() {
    // Atom : BRAC Expr KET FCalls
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_1() {
    // Atom : Var FCalls
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_2() {
    // Atoms : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_3() {
    // Atoms : Atom Atoms
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_4() {
    // BStmt : BREAK
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_5() {
    // BinOP0 : DIV
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_6() {
    // BinOP0 : MUL
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_7() {
    // BinOP1 : ADD
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_8() {
    // BinOP1 : SUB
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_9() {
    // BinOP2 : EQ
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_10() {
    // BinOP2 : G
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_11() {
    // BinOP2 : GEQ
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_12() {
    // BinOP2 : L
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_13() {
    // BinOP2 : LEQ
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_14() {
    // BinOP2 : NEQ
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_15() {
    // Brs : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_16() {
    // Brs : BR Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_17() {
    // EStmt : Var Vars EQUAL Expr BR Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_18() {
    // Expr : Expr1
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_19() {
    // Expr : Expr1 BinOP2 Expr
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_20() {
    // Expr0 : Atom
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_21() {
    // Expr0 : Atom BinOP0 Expr0
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_22() {
    // Expr1 : Expr0
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_23() {
    // Expr1 : Expr0 BinOP1 Expr1
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_24() {
    // F0Stmt : FOR Var EQUAL Expr TO Expr DO Brs Stmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_25() {
    // F1Stmt : FOR Var IN Expr DO Brs Stmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_26() {
    // FCStmt : FUNCTION Var FBRAC Vars KET Brs Stmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_27() {
    // FCall : FBRAC Atoms KET
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_28() {
    // FCalls : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_29() {
    // FCalls : FCall FCalls
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_30() {
    // IEStmt : IF Expr Brs THEN Brs NIEStmt NIEStmts ELSE Brs Stmt Stmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_31() {
    // IStmt : IF Expr Brs THEN Brs NIEStmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_32() {
    // NIEStmt : BStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_33() {
    // NIEStmt : EStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_34() {
    // NIEStmt : F0Stmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_35() {
    // NIEStmt : F1Stmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_36() {
    // NIEStmt : FCStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_37() {
    // NIEStmt : IStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_38() {
    // NIEStmt : RStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_39() {
    // NIEStmt : SStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_40() {
    // NIEStmt : WStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_41() {
    // NIEStmt : YStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_42() {
    // NIEStmts : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_43() {
    // NIEStmts : NIEStmt NIEStmts
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_44() {
    // RStmt : RETURN Vars BR Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_45() {
    // Root : Start
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_46() {
    // SStmt : Expr BR Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_47() {
    // Start : Brs Stmts
    this->accept();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_48() {
    // Stmt : IEStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_49() {
    // Stmt : NIEStmt
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_50() {
    // Stmts : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_51() {
    // Stmts : Stmt Stmts
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_52() {
    // Var : INT
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_53() {
    // Var : VAR
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_54() {
    // Vars : 
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_55() {
    // Vars : Var Vars
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_56() {
    // WStmt : WHILE Expr Brs DO Brs Stmts END Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::reduce_57() {
    // YStmt : YIELD Vars BR Brs
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_ADD() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BR() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BRAC() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_BREAK() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_DIV() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_DO() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_ELSE() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_END() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EOFF() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EQ() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_EQUAL() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FBRAC() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FOR() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_FUNCTION() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_G() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_GEQ() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_IF() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_IN() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_INT() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_KET() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_L() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_LEQ() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_MUL() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_NEQ() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_RETURN() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_SUB() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_THEN() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_TO() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_VAR() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_WHILE() {
    this->move();
    return std::make_shared<LNode>();
}

std::optional<std::shared_ptr<LNode>> LParser::shift_YIELD() {
    this->move();
    return std::make_shared<LNode>();
}
