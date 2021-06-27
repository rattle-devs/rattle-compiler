#ifndef TPYTHON_TOKEN_H
#define TPYTHON_TOKEN_H
typedef struct TOKEN_STRUCT{
	char* value;
	enum {
		TOKEN_ID,
		TOKEN_EQUALS,
		TOKEN_LPAREN,
		TOKEN_RPAREN,
		TOKEN_LBRACKET,
		TOKEN_RBRACKET,
		TOKEN_SPACING,
		TOKEN_COLON,
		TOKEN_COMMA,
		TOKEN_ARROW,
		TOKEN_INT
	} type
} token_T

token_T* init_token(char * value, int type)
#endif
