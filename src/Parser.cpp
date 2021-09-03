#include "Parser.hpp"

Parser::Parser(Lexer *lexer) {
    this->lexer = lexer;
    this->token = lexer->nextToken();
}

Parser::~Parser() {
    delete lexer;
}
