#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "include/lexer.h"
#include "include/token.h"
#include "lib/include/vector.h"

lexer_T* lexer_init(char* src, bool use_tab){
	lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
	lexer->src = src;
	lexer->src_size = strlen(src);
	lexer->use_tab = use_tab;
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

token_T* lexer_parse_indent(lexer_T* lexer){
	size_t line_indent = 0;
	if(lexer->use_tab){
		while (lexer->c == '\t') {
			line_indent++;
			lexer_advance(lexer);
		}
	}if(!lexer->use_tab){
		char counter = 0;
		while (lexer->c == ' ') {
			counter++;
			lexer_advance(lexer);
			if(counter == 4){
				counter = 0;
				line_indent++;
			}
			if(lexer->c != ' ' && counter != 0){
				char* error = "Indentation not divisible by 4";
				return init_token(error, TOKEN_ERROR);
			}
		}
	}

	if(line_indent + 1 == lexer->current_indent){
		lexer->current_indent = line_indent;
		char* cr = "\r";
		return init_token(cr, TOKEN_SEPARATOR);
	}
	if(line_indent == lexer->current_indent){
		return NULL;
	}
	if(line_indent - 1 == lexer->current_indent){
		lexer->current_indent = line_indent;
		char* ht = "\t";
		return init_token(ht, TOKEN_SEPARATOR);
	}
	char* error = "Unknown indentation error";
	return init_token(error, TOKEN_ERROR);
}

token_T* lexer_parse_comment(lexer_T* lexer){
	Vector* comment = vector_init(2, sizeof(char));
	while (lexer->c != '\n') {
		vector_append(comment, &lexer->c, 1);
		lexer_advance(lexer);
	}
	return init_token(vector_value(comment), TOKEN_COMMENT);
}

token_T* lexer_parse_alphanumeric(lexer_T* lexer){ //TODO implenet actual function
	Vector* text = vector_init(2, sizeof(char));

	return init_token(vector_value(text), TOKEN_IDENTIFIER); 
}

token_T* lexer_parse_token(lexer_T* lexer){
	if(lexer->new_line){
		lexer->new_line = false;
		token_T* result = lexer_parse_indent(lexer);
		if(result != NULL){
			return result;
		}
	}
	if(isspace(lexer->c)){
		lexer_skip_whitespace(lexer);
	}
	if(lexer->c == '#'){
		lexer->new_line = true;
		return lexer_parse_comment(lexer);
	}
	if(isalnum(lexer->c)){

	}

	return init_token(NULL, TOKEN_IDENTIFIER);
}

token_T* lexer_next_token(lexer_T* lexer){
	while(lexer->c != '\0'){
		if(!isspace(lexer->c)){
			return lexer_advance_with(lexer, lexer_parse_token(lexer));	
		}
	}
	return init_token(0, TOKEN_EOF);
}
