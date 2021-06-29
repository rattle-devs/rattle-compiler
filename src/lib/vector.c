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
		v->array = realloc(v->array, v->size * sizeof(int));
	}
	v->array[v->used++] = c;
}

void freeVector(Vector *v){
	free(v->array);
	free(v);
}


