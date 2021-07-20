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
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))
bool is_literal(char* text);
bool is_keyword(char* text);
bool is_separator(char text);
bool is_operator(char* text);
bool is_word_operator(char* text);
bool is_alphanumeric(char ch);
#endif //UTILS_H
