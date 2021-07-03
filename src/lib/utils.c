#include <stdbool.h>
#include <ctype.h>
#include "include/utils.h"

bool is_literal(char* text){
    /*
    char * reserved_literals[] = { RESERVED_LITERALS };
    for (int i = 0; i < ARRAY_LENGTH(reserved_literals); i++){
        if (text == reserved_literals[i]){
            return true;
        }
    }
     */
    if (isdigit(text[0]) || text[0] == '.' || text[0] == '\"') {
        return true;
    }
    return false;
}

bool is_keyword(char* text){char * reserved_keywords[] = { RESERVED_KEYWORDS };
    for (int i = 0; i < ARRAY_LENGTH(reserved_keywords); i++){
        if (text == reserved_keywords[i]){
            return true;
        }
    }
    return false;
}