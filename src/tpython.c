#include <stdbool.h>
#include "include/tpython.h"
#include "include/lexer.h"
#include "include/token.h"
#include "lib/include/vector.h"

void tpython_compile(char* file_path){ // finally file patch currently string
	/*token_T** tokens =*/ tpython_run_lexer(file_path);
	
}

token_T** tpython_run_lexer(char* src){
	Vector* tokens_vector = vector_init(8, sizeof(token_T*));
	lexer_T* lexer = lexer_init(src, false);
	token_T* current_token = NULL;
	do{
		current_token = lexer_next_token(lexer);
		vector_append(tokens_vector, &current_token, 1);
		if(current_token->type == TOKEN_ERROR){
			return vector_value(tokens_vector);	
		}
	}while(current_token->type != TOKEN_EOF);
	return (token_T**)vector_value(tokens_vector);
}
