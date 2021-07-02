#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "include/lexer.h"
#include "include/token.h"
#include "lib/include/vector.h"

lexer_T* init_lexer(char* src){
	lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
	lexer->src = src;
	lexer->src_size = strlen(src);
	lexer->i = 0;
	lexer->c = lexer->src[lexer->i];

	return lexer;
}

void lexer_advance(lexer_T* lexer){
	if(lexer->i < lexer->src_size && lexer->c != '\0'){
		lexer->i += 1;
		lexer->c = lexer->src[lexer->i];
	}
}

token_T* lexer_advance_with(lexer_T* lexer, token_T* token){
	lexer_advance(lexer);
	return token;
}

void lexer_skip_whitespace(lexer_T* lexer){
	while(lexer->c == ' ' || lexer->c == '\t' )
		lexer_advance(lexer);
}

token_T* lexer_parse_token(lexer_T* lexer){
	Vector* v = vector_init(1, sizeof(char));
	
	if(lexer->c == '#'){
		lexer_parse_comment(lexer);
	}
	while(!isspace(lexer->c) && lexer->c != '#'){
		vector_append(v, &lexer->c, 1);
		lexer_advance(lexer);
	}

	return init_token(vector_value(v), TOKEN_IDENTIFIER);
}

token_T* lexer_next_token(lexer_T* lexer){
	while(lexer->c != '\0'){
		if(!isspace(lexer->c)){
			return lexer_advance_with(lexer, lexer_parse_token(lexer));	
		}
	}
	return init_token(0, TOKEN_EOF);
}
