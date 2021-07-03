#include <stdbool.h>
#include <stdio.h>
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
	lexer->current_indent = 0;
	lexer->line_indent = 0;
	lexer->new_line = true;
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

//returns '\r' when indentation level falls back, '\t' when it advances, NULL when is stays the same, otherwise error
token_T* lexer_parse_indent(lexer_T* lexer){
	if(lexer->current_indent == 0){
		if(lexer->use_tab){ //source code uses tabs
			while (lexer->c == '\t') {
				lexer->line_indent++;
				lexer_advance(lexer);
				if(lexer->c == '#'){
					lexer->current_indent = 0;
					lexer->new_line = false;
					return NULL;
				}
			}
		}if(!lexer->use_tab){ //source code doesn't use tabs for indentation
            char counter = 0;
			while (lexer->c == ' ') {
				counter++;
				lexer_advance(lexer);
				if(counter == 4){
					counter = 0;
				lexer->line_indent++;
				}
				if(lexer->c == '#'){
					lexer->line_indent = 0;
					lexer->new_line = false;
					return NULL;
				}
				if(lexer->c != ' ' && counter != 0){
					char* error = "Indentation not divisible by 4";
					return token_init(error, TOKEN_ERROR);
				}
			}
		}
	}

	while(lexer->line_indent < lexer->current_indent){
		lexer->current_indent--;
		char* cr = "\r";
		return token_init(cr, TOKEN_SEPARATOR);
	}
    //indent level one higher - indicated as separator '\t'
	while(lexer->line_indent > lexer->current_indent){
		lexer->current_indent++;
		char* ht = "\t";
		return token_init(ht, TOKEN_SEPARATOR);
	}
    //no indentation change
	if(lexer->line_indent == lexer->current_indent){
		lexer->new_line = false;
		lexer->line_indent = 0;
		return NULL;
	}
	char* error = "Unknown indentation error";
	return token_init(error, TOKEN_ERROR);
}
//TODO: comments not matching indentation level should not fuck up the whole lexer
token_T* lexer_parse_comment(lexer_T* lexer){
	Vector* comment = vector_init(2, sizeof(char));
	while (lexer->c != '\n') {
		vector_append(comment, &lexer->c, 1);
		lexer_advance(lexer);
	}
	return token_init(vector_value(comment), TOKEN_COMMENT);
}

token_T* lexer_parse_alphanumeric(lexer_T* lexer){ //TODO: implement an actual function
	Vector* text = vector_init(2, sizeof(char));
	size_t token_type = TOKEN_IDENTIFIER;
	if (isdigit(lexer->c) || lexer->c == '.' || lexer->c == '\"') {
        token_type = TOKEN_LITERAL;
    }
	while (!isspace(lexer->c)) {
		vector_append(text, &lexer->c, 1);
		lexer_advance(lexer);
	}
	char* vec_val = (char*) vector_value(text);
	return token_init(vec_val, token_type);
}

//main function for token parsing
token_T* lexer_parse_token(lexer_T* lexer){
    //NOTE: line zero is a newline
	if(lexer->new_line){
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
		return lexer_parse_alphanumeric(lexer);	
	}
	if(lexer->c == '\n'){
		char* nl = "\n";
		return lexer_advance_with(lexer, token_init(nl, TOKEN_SEPARATOR));
	}
	if(lexer->c == '(' || lexer->c == ')' || lexer->c == '[' || lexer->c == ']'){
		char* ch = calloc(1, sizeof(char));
		memcpy(ch, &lexer->c,sizeof(char));
		return lexer_advance_with(lexer, token_init(ch, TOKEN_SEPARATOR));
	}
	char* err = "?";
	return lexer_advance_with(lexer, token_init(err, lexer->c));
}

token_T* lexer_next_token(lexer_T* lexer){
	while(lexer->c != '\0'){
		return lexer_parse_token(lexer);
	}
	return token_init("\0", TOKEN_EOF);
}
