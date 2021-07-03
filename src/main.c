#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "lib/include/vector.h"
#include "include/tpython.h"

int main() {
	Vector* v = vector_init(0, sizeof(char));
	for (char i = 33; i < 127; i++)
		vector_append(v, &i, 1);

	char* value = (char *)vector_value(v);
	printf("%s\n", value);
	free(value);
	//printf("%c\n", v->data[65]);
	//printf("%zu\n", v->reserved_size);
	//vector_free(v);
	
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(char));


	char* code = "func main() int\n    return 0";
	printf("CODE:\n%s\n----------------------", code);

	tpython_compile(code);

	printf("Hello World!\n");
	return 0;
}
