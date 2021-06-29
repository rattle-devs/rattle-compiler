#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H
#include <stdio.h>

typedef struct VECTOR_STRUCT{
	char* array;
	size_t used;
	size_t size;
} Vector;

Vector* init_vector(size_t initialSize);

void insertVector(Vector *v, char c);

void freeVector(Vector *v);

#endif 
