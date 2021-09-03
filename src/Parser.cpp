#include "Parser.hpp"

Parser::Parser(Lexer *_lexer) {
    this->lexer = _lexer;
    this->token = this->lexer->nextToken();
}

Parser::~Parser() {
    delete lexer;
}
