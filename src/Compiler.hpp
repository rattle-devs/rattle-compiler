#ifndef RATTLE_COMPILER_COMPILER_HPP
#define RATTLE_COMPILER_COMPILER_HPP

#include <queue>
#include "Token.hpp"
#include "src/AST/ASTProgram.hpp"

class Compiler {
    public:
        static bool compile(string *fileName);

        static queue<Token *> *parse(string *src);

};

#endif // RATTLE_COMPILER_COMPILER_HPP
