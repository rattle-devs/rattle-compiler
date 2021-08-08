#ifndef RATTLE_TOKEN_HPP
#define RATTLE_TOKEN_HPP
#define TOKEN_TYPES "encoding", "identifier", "keyword", "separator", "operator", "literal", "comment", "EOF", "ERROR"

#include <sys/types.h>
#include <string>

using namespace std;

enum struct TokenType : size_t {
    TOKEN_ENCODING,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_SEPARATOR,
    TOKEN_OPERATOR,
    TOKEN_LITERAL,
    TOKEN_COMMENT,
    TOKEN_EOF,
    TOKEN_ERROR,
    TOKEN_UNKNOWN
};

class Token {
    public:
        string *value;
        TokenType type;

        Token(string *_value, TokenType tokenType);

        ~Token();

        void print(size_t indent);

        [[nodiscard]] Token* clone() const { return new Token(*this); }
};

#endif //RATTLE_TOKEN_HPP
