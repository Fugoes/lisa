#include <iostream>

#include "src/LLexer.h"
#include "src/LParser.h"

int main() {
    std::string code =
            "if b == (a + c)(b 1 2) then\n"
            "   if d == e then"
            "       d = 1\n"
            "   end\n"
            "else\n"
            "   a = 23\n"
            "end\n"
            "break\n";
    auto parser = LParser(std::make_unique<LStringLexer>(code));
    parser.parse();
    return 0;
}