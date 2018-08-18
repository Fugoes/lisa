#ifndef LISA_LTOKEN_H
#define LISA_LTOKEN_H

#include <string>

#include "LNodeType.h"

class LToken {
public:
    LNodeType type{};

    std::string token;

    LToken(LNodeType type, std::string str);

    LToken() = default;

    std::string str();
};

#endif //LISA_LTOKEN_H
