#ifndef LISA_LLEXER_H
#define LISA_LLEXER_H

#include "LToken.h"

#include <string>
#include <memory>

class LLexer {
public:
    LLexer();

    std::shared_ptr<LToken> next_token();

    char prev_char{};

    std::shared_ptr<LToken> from_int(std::string token);

    std::shared_ptr<LToken> from_symbol(std::string token);

    std::shared_ptr<LToken> from_string(std::string token);

    virtual ~LLexer() = default;

private:
    virtual char peek() = 0;

    virtual void move() = 0;
};

class LStringLexer : public LLexer {
public:
    explicit LStringLexer(std::string str);

    ~LStringLexer() override = default;

private:
    std::string str;
    int cursor = 0;

    char peek() override;

    void move() override;
};


#endif //LISA_LLEXER_H
