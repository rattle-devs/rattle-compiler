#ifndef TPYTHON_TOKEN_H
#define TPYTHON_TOKEN_H

# if __WORDSIZE == 64
#  define SIZE_MAX              (18446744073709551615UL)
# else
#  define SIZE_MAX              (4294967295U)
# endif

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
		TOKEN_ALIGN_TO_SIZE_T = SIZE_MAX
	} type;
} token_T;

token_T* init_token(char * value, int type);
#endif //TPYTHON_TOKEN_H
