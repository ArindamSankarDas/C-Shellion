#include <stdlib.h>
#include "shell.h"

int main(int argc, char *argv[]){
	lsh_loop();

	//Perform any shutdown/cleanup.

	return EXIT_SUCCESS;
}
