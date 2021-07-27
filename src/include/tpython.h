#ifndef TPYTHON_H
#define TPYTHON_H
#include "../lib/include/vector.h"
#include "token.h"
bool tpython_compile(char* src);

Vector* tpython_run_lexer(char* src);
#endif //TPYTHON_H
