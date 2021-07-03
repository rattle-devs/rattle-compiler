#ifndef TPYTHON_H
#define TPYTHON_H
#include "token.h"
void tpython_compile(char* src);

token_T** tpython_run_lexer(char* src);
#endif //TPYTHON_H
