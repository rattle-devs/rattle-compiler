#ifndef UTILS_H
#define UTILS_H
#define RESERVED_LITERALS "true", "false", "null", "undefined"
#define RESERVED_KEYWORDS "func", "return", "args", "class", "struct", "if", "else", "for", "while",        \
                          "switch", "case", "and", "true", "false", "none", "as", "import", "from",         \
                          "or", "xor", "in", "is", "not", "continue", "break", "try", "catch", "panic",     \
                          "with", "delete", "assert", "elif", "finally", "lambda", "yield", "default",      \
                          "this", "public", "private", "protected", "implements", "extends", "interface",   \
                          "export", "const", "defer", "befriends"
#define OPERATORS "func", "return", "args", "class", "struct", "if", "else", "for", "while",        \
                          "switch", "case", "and", "true", "false", "none", "as", "import", "from",         \
                          "or", "xor", "in", "is", "not", "continue", "break", "try", "catch", "panic",     \
                          "with", "delete", "assert", "elif", "finally", "lambda", "yield", "default",      \
                          "this", "public", "private", "protected", "implements", "extends", "interface",   \
                          "export", "const", "defer", "befriends"
#define SEPARATORS "func", "return", "args", "class", "struct", "if", "else", "for", "while",        \
                          "switch", "case", "and", "true", "false", "none", "as", "import", "from",         \
                          "or", "xor", "in", "is", "not", "continue", "break", "try", "catch", "panic",     \
                          "with", "delete", "assert", "elif", "finally", "lambda", "yield", "default",      \
                          "this", "public", "private", "protected", "implements", "extends", "interface",   \
                          "export", "const", "defer", "befriends"
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))
bool is_literal(char* text);
bool is_keyword(char* text);
#endif //UTILS_H
