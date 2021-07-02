#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include "lib/include/vector.h"

int main() {
	Vector* v = vector_init(0, sizeof(char));
	for (char i = 33; i < 127; i++)
		vector_append(v, &i, 1);

	printf("%s\n", vector_value(v));
	printf("%c\n", v->data[65]);
	printf("%zu\n", v->reserved_size);
	vector_free(v);


	printf("Hello World!\n");
	return 0;
}
