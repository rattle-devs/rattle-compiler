#ifndef RATTLE_LEXER_HPP
#define RATTLE_LEXER_HPP

#include "token.hpp"
#include <cstdio>

class Lexer {
    public:
        explicit Lexer(string *_src);

        ~Lexer();

        void advance();

        Token *advanceWith(Token *token);

        void skipWhitespace();

        /**
         * Parse Indent on line beginning
         * @return '\r' when indentation level falls back, '\t' when it advances, NULL when is stays the same, otherwise error
         */
        Token *parseIndent();

        Token *parseComment();

        Token *parseAlphanumeric();

        Token *nextToken();

        [[nodiscard]] size_t getCurrentIndent() const;


    private:
        string *src;
        size_t src_size;
        size_t i; // current place
        size_t current_indent;
        size_t line_indent;
        char c;
        bool new_line;
        char _pad[6];

        Token *parseOperatorSeparator();

        Token *parseToken();
};

#endif // RATTLE_LEXER_HPP
