#include "Parser.hpp"
#include "AST/ASTProgram.hpp"
#include "AST/ASTStatement.hpp"

Parser::Parser(Lexer *_lexer) {
    this->lexer = _lexer;
    this->token = this->lexer->nextToken();
}

Parser::~Parser() {
    delete lexer;
}

void Parser::test() {
    auto* ap = new ASTProgram();
    auto* array = new ASTStatementArray();
    ap->statements->push_back(array);
    auto* test = (ASTStatementArray*)ap->statements->at(0);
    test->statements = new vector<ASTStatement*>;
}
