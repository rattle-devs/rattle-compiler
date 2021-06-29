#include <stdio.h>
#include "lib/include/vector.h"

int main() {
	Vector* v = init_vector(2);
	for (char i = 0; i < 100; i++)
		insertVector(v, i);

	printf("%c\n", v->array[65]);
	freeVector(v);
	printf("Hello World!\n");
	return 0;
}
