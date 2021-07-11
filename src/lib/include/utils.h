#ifndef UTILS_H
#define UTILS_H
#define LITERALS   "true", "false", "null", "undefined"
#define KEYWORDS   "func", "return", "args", "class", "struct", "if", "else", "for", "while",      \
                            "switch", "case", "true", "false", "none", "as", "import", "from", "export",    \
                            "continue", "break", "try", "catch", "panic", "const", "defer", "befriends",    \
                            "with", "delete", "assert", "elif", "finally", "lambda", "yield", "default",    \
                            "this", "public", "private", "protected", "implements", "extends", "interface",
#define OPERATORS           "+", "-", "*", "/", "%", "**", "//",            \
                            "+=", "-=", "*=", "/=", "%=", "**=", "//=",     \
                            "<<", ">>", "<<=", ">>=",                       \
                            "=", "==", "!=", ">", "<", "&", ".", "++", "--"
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
