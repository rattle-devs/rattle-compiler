#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H
#include <stdio.h>
#include <stdbool.h>

typedef struct VECTOR_STRUCT{
	char* data;					// data
	size_t count;				// current amount of elements
	size_t reserved_size;		// currently reserved memory size
	size_t element_size;		// size of one element
} Vector;

bool vector_realloc(Vector* v, size_t new_count);

Vector* vector_init(size_t count_of_elements, size_t size_of_element);

void vector_free(Vector* v);

void* vector_data(Vector* v);

void* vector_value(Vector* v);

size_t vector_size(const Vector* v);

size_t vector_max_count(const Vector* v);

bool vector_append(Vector* v, const void* values, size_t count);

#endif //LIB_VECTOR_H
