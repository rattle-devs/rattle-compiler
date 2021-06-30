#include <stdio.h>
#include "lib/include/vector.h"

int main() {
	Vector* v = init_vector(2);
	for (char i = 33; i < 127; i++)
		insertVector(v, i);

	printf("%c\n", v->array[65]);
	printf("%s\n", getVectorValue(v));
	printf("%ld\n", v->size);
	freeVector(v);


	printf("Hello World!\n");
	return 0;
}
