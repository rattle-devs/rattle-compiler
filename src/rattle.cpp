#include "include/lexer.hpp"
#include "include/rattle.hpp"
#include "lib/utils/utils.hpp"

bool Compiler::compile(string *fileName) {
    string *src = nullptr;
    src = readFileToString(fileName);
    if (src->length() > 0) {
        queue<Token *> tokens = Compiler::lex(src);
        Token *last = tokens.back();
        if (last->type == TokenType::TOKEN_EOF) {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }
    printf("rattle: fatal error: %s: Error reading file\n", fileName->c_str());
    return EXIT_FAILURE;
}

queue<Token *> Compiler::lex(string *src) {
    queue<Token *> tokens;
    auto *lexer = new Lexer(src);
    Token *currentToken = nullptr;
    do {
        currentToken = lexer->nextToken();
        tokens.push(currentToken);
        if (currentToken->type == TokenType::TOKEN_ERROR) {
            currentToken->print(lexer->getCurrentIndent());
            return tokens;
        }
        currentToken->print(lexer->getCurrentIndent());
    } while (currentToken->type != TokenType::TOKEN_EOF);
    return tokens;
}
