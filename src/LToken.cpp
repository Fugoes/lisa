#include "LToken.h"

#include <sstream>

std::string LToken::str() {
    std::stringstream ss;
    switch (this->type) {
        case LNodeType::INT:
            ss << "INT: " << this->token;
            break;
        case LNodeType::VAR:
            ss << "VAR: " << this->token;
            break;
        case LNodeType::EQUAL:
            ss << "EQUAL";
            break;
        case LNodeType::L:
            ss << "L";
            break;
        case LNodeType::G:
            ss << "G";
            break;
        case LNodeType::BRAC:
            ss << "BRAC";
            break;
        case LNodeType::KET:
            ss << "KET";
            break;
        case LNodeType::BR:
            ss << "BR";
            break;
        case LNodeType::ADD:
            ss << "ADD";
            break;
        case LNodeType::SUB:
            ss << "SUB";
            break;
        case LNodeType::EQ:
            ss << "EQ";
            break;
        case LNodeType::NEQ:
            ss << "NEQ";
            break;
        case LNodeType::LEQ:
            ss << "LEQ";
            break;
        case LNodeType::GEQ:
            ss << "GEQ";
            break;
        case LNodeType::FUNCTION:
            ss << "FUNCTION";
            break;
        case LNodeType::IF:
            ss << "IF";
            break;
        case LNodeType::THEN:
            ss << "THEN";
            break;
        case LNodeType::ELSE:
            ss << "ELSE";
            break;
        case LNodeType::END:
            ss << "END";
            break;
        case LNodeType::EOFF:
            ss << "EOFF";
            break;
        default:
            ss << "INVALID";
            break;
    }
    return ss.str();
}

LToken::LToken(LNodeType type, std::string str) {
    this->type = type;
    this->token = std::move(str);
}
