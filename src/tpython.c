#define _GNU_SOURCE
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/tpython.h"
#include "include/lexer.h"
#include "include/token.h"
#include "lib/include/vector.h"

bool tpython_compile(char* file_name){ // finally file patch currently string
  char* src = NULL;
  size_t lenght;
  FILE* fp = fopen (file_name, "rb");
  if(fp == NULL){
    printf("rattle: fatal error: %s: No such file or directory\n", file_name);
    return EXIT_FAILURE;
  }
  ssize_t bytes_read = getdelim( &src, &lenght, '\0', fp);
  if(bytes_read != -1){
    Vector* tokens = tpython_run_lexer(src);
    token_T* last = vector_back(tokens);
	if(last->type == TOKEN_EOF){
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
  }
  printf("rattle: fatal error: %s: Error reading file\n", file_name);
  return EXIT_FAILURE;
	
}

Vector* tpython_run_lexer(char* src){
	Vector* tokens_vector = vector_init(8, sizeof(token_T));
	lexer_T* lexer = lexer_init(src, true);
	token_T* current_token = NULL;
	do{
		current_token = lexer_next_token(lexer);
		vector_append(tokens_vector, current_token, 1);
		if(current_token->type == TOKEN_ERROR){
			token_print(current_token);
			return tokens_vector;
		}
        token_print(current_token);
	} while(current_token->type != TOKEN_EOF);
	return tokens_vector;
}
