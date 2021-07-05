#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "lib/include/vector.h"
#include "include/tpython.h"

int main(int argc, char **argv) {
	if(argc < 2){
    printf("rattle: fatal error: no input files\n");
    return EXIT_FAILURE;
  }
	return tpython_compile(argv[1]);
}
