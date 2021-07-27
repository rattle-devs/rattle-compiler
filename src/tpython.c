#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/tpython.h"
#include "include/lexer.h"
#include "include/token.h"
#include <vector.h>

bool tpython_compile(char* file_name){ // finally file patch currently string
  Vector* src = vector_init(64, sizeof(char));
  FILE* fp = fopen (file_name, "rb");
  if(fp == NULL){
    printf("rattle: fatal error: %s: No such file or directory\n", file_name);
    return EXIT_FAILURE;
  }
  char ch;
  while((ch = (char)fgetc(fp)) != EOF)
      vector_append(src, &ch, 1);

  if(vector_count(src) > 0){
    Vector* tokens = tpython_run_lexer(vector_value(src));
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
	lexer_T* lexer = lexer_init(src);
	token_T* current_token = NULL;
	do{
		current_token = lexer_next_token(lexer);
		vector_append(tokens_vector, current_token, 1);
		if(current_token->type == TOKEN_ERROR){
			token_print(current_token, lexer->current_indent);
			return tokens_vector;
		}
        token_print(current_token, lexer->current_indent);
	} while(current_token->type != TOKEN_EOF);
	return tokens_vector;
}
