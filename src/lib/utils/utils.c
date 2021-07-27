#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "src/lib/utils/utils.h"

bool is_literal(char* text){
    /*
    char * literals[] = { LITERALS };
    for (int i = 0; i < ARRAY_LENGTH(literals); i++){
        if (!strcmp(text == literals[i])){
            return true;
        }
    }
     */
    if (isdigit(text[0]) || text[0] == '.' || text[0] == '\"' || text[0] == '\'' || text[0] == '`') {
        return true;
    }
    return false;
}

bool is_keyword(char* text){
    char * keywords[] = { KEYWORDS };
    for (int i = 0; i < ARRAY_LENGTH(keywords); i++){
        if (!strcmp(text, keywords[i])){
            return true;
        }
    }
    return false;
}
bool is_operator(char* text){
    char * operators[] = { OPERATORS };
    for (int i = 0; i < ARRAY_LENGTH(operators); i++){
        if (!strcmp(text, operators[i])){
            return true;
        }
    }
    return false;
}
bool is_separator(char text){
    char separators[] = { SEPARATORS };
    for (int i = 0; i < ARRAY_LENGTH(separators); i++){
        if (text == separators[i]){
            return true;
        }
    }
    return false;
}
bool is_word_operator(char* text){
    char * word_operators[] = { WORD_OPERATORS };
    for (int i = 0; i < ARRAY_LENGTH(word_operators); i++){
        if (!strcmp(text, word_operators[i])){
            return true;
        }
    }
    return false;
}

bool is_alphanumeric(char ch){
	return isalnum(ch) || ch == '"' || ch == '\'' || ch == '`' || ch == '_';	
}
