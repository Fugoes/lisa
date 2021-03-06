#include "LLexer.h"

#include <sstream>

static inline int is_num(char c) {
    return c >= '0' && c <= '9';
}

static inline int is_word_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

static inline int is_blank(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == 0;
}

static inline int is_single_symbol(char c) {
    return c == '+' || c == '(' || c == ')' || c == ',' || c == '\n';
}

static inline int is_double_symbol(char c) {
    return c == '<' || c == '>' || c == '~' || c == '=';
}

static inline int is_minus(char c) {
    return c == '-';
}

LStringLexer::LStringLexer(std::string str) {
    this->str = std::move(str);
    this->prev_char = 0;
    this->cursor = 0;
}

char LStringLexer::peek() {
    if (this->cursor < this->str.length()) {
        return this->str[this->cursor];
    } else {
        return 0;
    }
}

void LStringLexer::move() {
    if (this->cursor < this->str.length()) {
        this->prev_char = this->str[this->cursor];
        this->cursor++;
    }
}

std::shared_ptr<LToken> LLexer::next_token() {
    if (this->peek() == 0) return std::make_shared<LToken>(LNodeType::EOFF, "");
    int state = 0;
    std::stringstream ss;
    while (true) {
        char c = this->peek();
        switch (state) {
            case 0:
                if (is_blank(c)) {
                    state = 0;
                } else if (is_num(c)) {
                    state = 1;
                } else if (is_word_char(c)) {
                    state = 2;
                } else if (is_minus(c)) {
                    state = 3;
                } else if (is_single_symbol(c)) {
                    ss << c;
                    auto token = this->from_symbol(ss.str());
                    this->move();
                    return token;
                } else if (is_double_symbol(c)) {
                    ss << c;
                    this->move();
                    if (this->peek() == '=') {
                        ss << c;
                        this->move();
                    }
                    return this->from_symbol(ss.str());
                }
                break;
            case 1:
                if (!is_num(c)) {
                    return this->from_int(ss.str());
                }
                break;
            case 2:
                if (!(is_word_char(c) || is_num(c))) {
                    return this->from_string(ss.str());
                }
                break;
            case 3:
                if (is_num(3)) {
                    state = 1;
                } else {
                    return this->from_symbol(ss.str());
                }
                break;
            default:
                return nullptr;
        }
        if (!is_blank(c)) ss << c;
        this->move();
    }
}

LLexer::LLexer() {
    this->prev_char = 0;
}

std::shared_ptr<LToken> LLexer::from_int(std::string token) {
    return std::make_shared<LToken>(LNodeType::INT, std::move(token));
}

std::shared_ptr<LToken> LLexer::from_symbol(std::string token) {
    LNodeType type = LNodeType::INVALID;
    if (token.size() == 1) {
        switch (token[0]) {
            case '=':
                type = LNodeType::EQUAL;
                break;
            case '<':
                type = LNodeType::L;
                break;
            case '>':
                type = LNodeType::G;
                break;
            case '(':
                if (this->prev_char == ')' || is_num(this->prev_char) || is_word_char(this->prev_char)) {
                    type = LNodeType::FBRAC;
                } else {
                    type = LNodeType::BRAC;
                }
                break;
            case ')':
                type = LNodeType::KET;
                break;
            case '\n':
                type = LNodeType::BR;
                break;
            case '+':
                type = LNodeType::ADD;
                break;
            case '-':
                type = LNodeType::SUB;
                break;
            default:
                return nullptr;
        }
    } else if (token.size() == 2) {
        switch (token[0]) {
            case '=':
                type = LNodeType::EQ;
                break;
            case '~':
                type = LNodeType::NEQ;
                break;
            case '<':
                type = LNodeType::LEQ;
                break;
            case '>':
                type = LNodeType::GEQ;
                break;
            default:
                return nullptr;
        }
    }
    if (type == LNodeType::INVALID) {
        return nullptr;
    } else {
        return std::make_shared<LToken>(type, std::move(token));
    }
}

std::shared_ptr<LToken> LLexer::from_string(std::string token) {
    if (token == "break")
        return std::make_shared<LToken>(LNodeType::BREAK, std::move(token));
    if (token == "do")
        return std::make_shared<LToken>(LNodeType::DO, std::move(token));
    if (token == "else")
        return std::make_shared<LToken>(LNodeType::ELSE, std::move(token));
    if (token == "end")
        return std::make_shared<LToken>(LNodeType::END, std::move(token));
    if (token == "for")
        return std::make_shared<LToken>(LNodeType::FOR, std::move(token));
    if (token == "function")
        return std::make_shared<LToken>(LNodeType::FUNCTION, std::move(token));
    if (token == "if")
        return std::make_shared<LToken>(LNodeType::IF, std::move(token));
    if (token == "in")
        return std::make_shared<LToken>(LNodeType::IN, std::move(token));
    if (token == "return")
        return std::make_shared<LToken>(LNodeType::RETURN, std::move(token));
    if (token == "then")
        return std::make_shared<LToken>(LNodeType::THEN, std::move(token));
    if (token == "to")
        return std::make_shared<LToken>(LNodeType::TO, std::move(token));
    if (token == "while")
        return std::make_shared<LToken>(LNodeType::WHILE, std::move(token));
    if (token == "yield")
        return std::make_shared<LToken>(LNodeType::YIELD, std::move(token));
    return std::make_shared<LToken>(LNodeType::VAR, std::move(token));
}
