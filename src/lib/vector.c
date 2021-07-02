#include "include/vector.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define GROWTH_FACTOR 2
#define DEFAULT_COUNT_OF_ELEMENTS 8
#define MINIMUM_COUNT_OF_ELEMENTS 2


bool vector_realloc(Vector* v, size_t new_count){
	const size_t new_size = new_count * v->element_size;
	char* new_data = realloc(v->data, new_size);
	if(!new_data){
		return false;
	}

	v->reserved_size = new_size;
	v->data = new_data;
	return true;
}

Vector* vector_init(size_t count_of_elements, size_t size_of_element){
	Vector* v = (Vector*)malloc(sizeof(struct VECTOR_STRUCT));
	if(v != NULL){
		v->data = NULL;
		v->count = 0;
		v->element_size = size_of_element;
		
		if(count_of_elements < MINIMUM_COUNT_OF_ELEMENTS){
			count_of_elements = DEFAULT_COUNT_OF_ELEMENTS;
		}

		if(size_of_element < 1 || !vector_realloc(v, count_of_elements)){
			free(v);
			v = NULL;
		}
	}
	return v;
}

void vector_free(Vector *v){
	if(v->reserved_size != 0){
		free(v->data);
	}
	free(v);
}

void* vector_data(Vector* v){
	return v->data;
}

char* vector_value(Vector *v){
	vector_realloc(v, vector_size(v) + 1);
	const int i = 0;
	vector_append(v, &i, 1);
	char* data = v->data;
	free(v);
	return data;
}

size_t vector_size(const Vector* v) {
  return v->count * v->element_size;
}

size_t vector_max_count(const Vector* v){
	return v->reserved_size / v->element_size;
}

bool vector_append(Vector* v, const void* values, size_t count){
	const size_t count_new = count + v->count;
	
	if(vector_max_count(v) < count_new){
		size_t max_count_to_reserve = (size_t)vector_max_count(v) * GROWTH_FACTOR;
		while (count_new > max_count_to_reserve) {
			max_count_to_reserve *= GROWTH_FACTOR;
		}

		if (!vector_realloc(v, max_count_to_reserve)) {
			return false;
		}
	}

	if (memcpy(v->data + v->count * v->element_size,
                      values,
                      v->element_size * count) == NULL) {
		return false;
	}

	v->count = count_new;
	return true;
}

