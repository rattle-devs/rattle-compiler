#ifndef UTILS_H
#define UTILS_H
#define LITERALS    "true", "false", "null", "undefined"
#define KEYWORDS    "async", "await", "break", "const", "continue", "defer", "else", \
                    "for", "func", "if", "import", "interface", "package", "panic",  \
                    "return", "struct", "switch", "type", "while",

#define OPERATORS           "+", "-", "*", "/", "%", "**", "//",                        \
                            "+=", "-=", "*=", "/=", "%=", "**=", "//=",                 \
                            "<<", ">>", "<<=", ">>=",                                   \
                            "=", "==", "!=", ">", "<", "&", ".", "++", "--", "<=", ">="
#define SEPARATORS          '\n', '(', ')', '[', ']', ','
#define WORD_OPERATORS      "and", "or", "in", "xor", "not", "is"

#include <string>

using namespace std;

bool isLiteral(string *text);

bool isKeyword(string *text);

bool isSeparator(string *text);

bool isOperator(string *text);

bool isWordOperator(string *text);

bool isAlphanumeric(char ch);

string *readFileToString(const string *filename);

#endif //UTILS_H
