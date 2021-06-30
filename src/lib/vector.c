#include "include/vector.h"
#include <stdlib.h>

Vector* init_vector(size_t initialSize){
	Vector* v = calloc(1, sizeof(struct VECTOR_STRUCT));
	v->array = malloc(initialSize * sizeof(char));
	v->used = 0;
	v->size = initialSize;
	return v;
}

void insertVector(Vector *v, char c){
	if(v->used == v->size){
		v->size*=2;
		v->array = realloc(v->array, v->size * sizeof(char));
	}
	v->array[v->used++] = c;
}

char* getVectorValue(Vector *v){
	v->array[v->used++] = '\0';
	v->size = v->used;
	v->array = realloc(v->array, v->size * sizeof(char));
	return v->array;
}

void freeVector(Vector *v){
	free(v->array);
	free(v);
}


