#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>
#include "include/token.h"

token_T* token_init(char * value, size_t type){
	token_T* token = calloc(1, sizeof(struct TOKEN_STRUCT));
	token->value = value;
	token->type = type;

	return token;
}

void token_print(token_T* token){
    char * unescaped[] = {
            "\n",
            "\t",
            "\r",
            "\0"
    };
    char * escaped[] = {
            "\\n",
            "\\t",
            "\\r",
            "EOF"
    };
    char* tempDebugValue = token->value;
    for (int i = 0; i < sizeof(unescaped)/sizeof(unescaped[0]); i++){
        if (*token->value == *unescaped[i]){
            tempDebugValue = escaped[i];
            break;
        }
    }
    printf("(\"%s\", %zu)\n", tempDebugValue, token->type);
}
