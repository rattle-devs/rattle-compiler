#ifndef TPYTHON_TOKEN_H
#define TPYTHON_TOKEN_H
#define TOKEN_TYPES "encoding", "identifier", "keyword", "separator", "operator", "literal", "comment", "EOF", "ERROR"
#include <sys/types.h>
#include <stdint.h>

typedef struct TOKEN_STRUCT{
	char* value;
	enum {
		TOKEN_ENCODING,
		TOKEN_IDENTIFIER,
		TOKEN_KEYWORD,
		TOKEN_SEPARATOR,
		TOKEN_OPERATOR,
		TOKEN_LITERAL,
		TOKEN_COMMENT,
		TOKEN_EOF,
		TOKEN_ERROR,
		TOKEN_UNKNOWN,
		TOKEN_ALIGN_TO_SIZE_T = SIZE_MAX
	} type;
} token_T;

token_T* token_init(char * value, size_t type);

void token_print(token_T* token);
#endif //TPYTHON_TOKEN_H
