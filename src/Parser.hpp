#ifndef RATTLE_COMPILER_PARSER_HPP
#define RATTLE_COMPILER_PARSER_HPP


#include "Lexer.hpp"

class Parser {
    public:
        explicit Parser(Lexer *lexer);

        ~Parser();

        void test();



    private:
        Lexer *lexer;
        Token *token;

};


#endif //RATTLE_COMPILER_PARSER_HPP
