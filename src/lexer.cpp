#include <cstring>
#include "src/lib/utils/utils.hpp"
#include "include/lexer.hpp"
Lexer::Lexer(string *_src) {
    this->src = _src;
    this->src_size = _src->size();
    this->i = 0;
    this->c = this->src->at(this->i);
    this->current_indent = 0;
    this->line_indent = 0;
    this->new_line = true;
}

Lexer::~Lexer() {
    delete this->src;
}

void Lexer::advance() {
    if (this->i < this->src_size - 1) {
        this->i += 1;
        this->c = this->src->at(this->i);
    }
}

Token *Lexer::advanceWith(Token *token) {
    this->advance();
    return token;
}

void Lexer::skipWhitespace() {
    while (this->c == ' ' || this->c == '\t' || this->c == '\r')
        this->advance();
}

Token *Lexer::parseIndent() {
    if (this->line_indent == 0) {
        size_t counter = 0;
        while (this->c == ' ' || this->c == '\t') {
            if (this->c == ' ')
                counter++;
            else
                counter += 4;

            this->advance();
            if (counter == 4) {
                counter = 0;
                this->line_indent++;
            }
            if (this->c == '#') {
                this->line_indent = 0;
                this->new_line = false;
                return nullptr;
            }
            if (this->c != ' ' && counter != 0) {
                auto *error = new string("Indentation not divisible by 4");
                return new Token(error, TokenType::TOKEN_ERROR);
            }
        }
    }
    //printf("Line indent: %zu, current indent: %zu\n", lexer->line_indent, lexer->current_indent);
    if (this->line_indent < this->current_indent) {

        this->current_indent--;
        auto *cr = new string("\r");
        return new Token(cr, TokenType::TOKEN_SEPARATOR);
    }
    //indent level one higher - indicated as separator '\t'
    if (this->line_indent > this->current_indent) {
        this->current_indent++;
        auto *ht = new string("\t");
        return new Token(ht, TokenType::TOKEN_SEPARATOR);
    }
    //no indentation change
    if (this->line_indent == this->current_indent) {
        this->new_line = false;
        this->line_indent = 0;
        return nullptr;
    }
    auto *error = new string("Unknown indentation error");
    return new Token(error, TokenType::TOKEN_ERROR);
}

Token *Lexer::parseComment() {
    auto *comment = new string();

    while (this->c != '\n' && this->c != '\0' && this->c != '\r') {
        comment->push_back(this->c);
        this->advance();
    }
    return new Token(comment, TokenType::TOKEN_COMMENT);
}

Token *Lexer::parseAlphanumeric() {
    auto *text = new string();
    TokenType token_type = TokenType::TOKEN_IDENTIFIER;
    if (this->c == '\'' || this->c == '"' || this->c == '`') {
        char quote = this->c;
        text->push_back(quote);
        do {
            this->advance();
            if (this->c == '\\') {
                this->advance();
                text->push_back(this->c);
                this->advance();
                text->push_back(this->c);
            } else
                text->push_back(this->c);
        } while (this->c != quote);
        this->advance();
        if (isspace(this->c)) {
            return new Token(text, TokenType::TOKEN_LITERAL);
        }
    }
    while (isAlphanumeric(this->c)) {
        text->push_back(this->c);
        this->advance();
    }
    if (isLiteral(text)) {
        token_type = TokenType::TOKEN_LITERAL;
    }
    if (isKeyword(text)) {
        token_type = TokenType::TOKEN_KEYWORD;
    }
    return new Token(text, token_type);
}

Token *Lexer::parseOperatorSeparator() {
    auto *text = new string();
    TokenType token_type = TokenType::TOKEN_UNKNOWN;
    if (isSeparator(new string(&this->c))) {
        if (this->c == '\n') {
            this->new_line = true;
        }
        text->push_back(this->c);
        token_type = TokenType::TOKEN_SEPARATOR;
        return this->advanceWith(new Token(text, token_type));
    }
    while (!isalnum(this->c) && !isspace(this->c)) {
        text->push_back(this->c);
        this->advance();
    }
    if (isOperator(text)) {
        token_type = TokenType::TOKEN_OPERATOR;
    } else {
        return nullptr;
    }
    return new Token(text, token_type);
}

Token *Lexer::parseToken() {
    //NOTE: line zero is a newline
    Token *result;
    if (this->new_line) {
        result = this->parseIndent();
        if (result != nullptr) {
            return result;
        }
    }
    if (isspace(this->c)) {
        this->skipWhitespace();
    }
    if (this->c == '#') {
        return this->parseComment();
    }
    if (isAlphanumeric(this->c)) {
        return this->parseAlphanumeric();
    }
    result = this->parseOperatorSeparator();
    if (result != nullptr) {
        return result;
    }
    auto *err = new string(&this->c);
    return this->advanceWith(new Token(err, TokenType::TOKEN_ERROR));
}

Token *Lexer::nextToken() {
    if (this->i < this->src_size - 1) {
        return this->parseToken();
    }
    if (this->current_indent > 0) {
        this->current_indent--;
        return new Token(new string("\r"), TokenType::TOKEN_SEPARATOR);
    }
    return new Token(new string("\0"), TokenType::TOKEN_EOF);
}

size_t Lexer::getCurrentIndent() const {
    return this->current_indent;
}

