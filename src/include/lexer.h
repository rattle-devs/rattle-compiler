#ifndef TPYTHON_LEXER_H
#define TPYTHON_LEXER_H
#include "token.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct LEXER_STRUCT{
	char* src;
	size_t src_size;
	bool use_tab;
	char c;
	size_t i;
	bool new_line;
	size_t current_indent;

} lexer_T;

lexer_T* lexer_init(char* src, bool use_tab);

void lexer_advance(lexer_T* lexer);

token_T* lexer_advance_with(lexer_T* lexer, token_T* token);

void lexer_skip_whitespace(lexer_T* lexer);

token_T* lexer_parse_indent(lexer_T* lexer);

token_T* lexer_parse_comment(lexer_T* lexer);

token_T* lexer_parse_alphanumeric(lexer_T* lexer);

token_T* lexer_parse_symbol(lexer_T* lexer);

token_T* lexer_next_token(lexer_T* lexer);


#endif // TPYTHON_LEXER_H 
