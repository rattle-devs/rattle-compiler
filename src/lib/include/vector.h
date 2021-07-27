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

// Release memory
void vector_free(Vector* v);

// Returns the item at index position in the vector.
void* vector_at(Vector* v, size_t index);

// Returns the first item in the vector. (arr[0])
void* vector_front(Vector* v);

// Returns the last item in the vector. (arr[n])
void* vector_back(Vector* v);

// Returns a pointer to the data stored in the vector. The pointer can be used to access and modify the items in the vector.
void* vector_data(Vector* v);

// Returns a pointer to the data stored in the vector. The vector is destryed
void* vector_value(Vector* v);

size_t vector_count(const Vector* v);

size_t vector_size(const Vector* v);

size_t vector_max_count(const Vector* v);

bool vector_append(Vector* v, const void* values, size_t count);

#endif //LIB_VECTOR_H
