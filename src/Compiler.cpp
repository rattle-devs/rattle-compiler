#include "include/Lexer.hpp"
#include "include/Compiler.hpp"
#include "lib/utils/utils.hpp"

bool Compiler::compile(string *fileName) {
    string *src = nullptr;
    src = readFileToString(fileName);
    if (src->length() > 0) {
        queue<Token *>* tokens = Compiler::lex(src);
        Token *last = tokens->back()->deepClone();
        Token *token;
        while (!tokens->empty()){
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
}

queue<Token *>* Compiler::lex(string *src) {
    auto* tokens = new queue<Token*>();
    auto *lexer = new Lexer(src);
    Token *currentToken = nullptr;
    do {
        currentToken = lexer->nextToken();
        tokens->push(currentToken);
        if (currentToken->type == TokenType::TOKEN_ERROR) {
            currentToken->print(lexer->getCurrentIndent());
            return tokens;
        }
        currentToken->print(lexer->getCurrentIndent());
    } while (currentToken->type != TokenType::TOKEN_EOF);
    return tokens;
}
