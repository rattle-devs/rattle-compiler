#include <cstdio>
#include "include/Token.hpp"

using namespace std;

const int escapedCharacters = 4;

const string tokenTypes[] = {TOKEN_TYPES};

const string escapeTable[escapedCharacters][2] = {
        {"\n", "\\n"},
        {"\t", "\\t"},
        {"\r", "\\r"},
        {"\0", "EOF"}
};

Token::Token(string *_value, TokenType tokenType) {
    this->value = _value;
    this->type = tokenType;
}

Token::~Token() {
    delete this->value;
}

void Token::print(size_t indent) {

    string tempDebugValue = *this->value;

    for (const auto &i : escapeTable) {
        if (*this->value == i[0]) {
            tempDebugValue = i[1];
            break;
        }
    }

    for (size_t i = 0; i < indent; i++) {
        printf("\t");
    }

    printf("\t%-16s\t%s\n", tokenTypes[(size_t)this->type].c_str(), tempDebugValue.c_str());
    if (this->value->starts_with('\n')) {
        printf("\n");
    }
}
