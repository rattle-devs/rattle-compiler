#ifndef TPYTHON_TOKEN_H
#define TPYTHON_TOKEN_H
typedef struct TOKEN_STRUCT{
	char* value;
	enum {
		TOKEN_IDENTIFIER,
		TOKEN_KEYWORD,
		TOKEN_SEPARATOR,
		TOKEN_OPERATOR,
		TOKEN_LITERAL,
		TOKEN_COMMENT
	} type
} token_T

token_T* init_token(char * value, int type)
#endif
