#include "Lexer.hpp"
#include "Compiler.hpp"
#include "utils.hpp"

bool Compiler::compile(string *fileName) {
    string *src = nullptr;
    src = readFileToString(fileName);
    if (src->length() > 0) {
        queue<Token *> *tokens = Compiler::parse(src);
        Token *last = tokens->back()->deepClone();
        Token *token;
        while (!tokens->empty()) {
            token = tokens->front();
            delete token;
            tokens->pop();
        }
        delete tokens;
        if (last->type == TokenType::TOKEN_EOF) {
            delete last;
            return EXIT_SUCCESS;
        }
        delete last;
        return EXIT_FAILURE;
    }
    printf("rattle: fatal error: %s: Error reading file\n", fileName->c_str());
    return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

queue<Token *> *Compiler::parse(string *src) {
    auto *tokens = new queue<Token *>();
    auto *lexer = new Lexer(src);
    Token *currentToken = nullptr;
    do {
        currentToken = lexer->nextToken();
        tokens->push(currentToken);
        if (currentToken->type == TokenType::TOKEN_ERROR) {
            currentToken->print(lexer->getCurrentIndent());
            //return tokens;
        }
        currentToken->print(lexer->getCurrentIndent());
    } while (currentToken->type != TokenType::TOKEN_EOF);
    //return tokens;
    return nullptr;
}
