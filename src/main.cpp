#include "include/rattle.hpp"

int main(int argc, char **argv) {

	if(argc < 2){
		printf("rattle: fatal error: no input files\n");
		return EXIT_FAILURE;
	}
	return Compiler::compile(new string(argv[1]));
}
