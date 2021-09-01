#ifndef RATTLE_HPP
#define RATTLE_HPP

#include <queue>
#include "Token.hpp"

class Compiler {
    public:
        static bool compile(string *fileName);

        static queue<Token *>* lex(string *src);

};

#endif // RATTLE_HPP
