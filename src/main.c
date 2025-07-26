#include <stdlib.h>
#include "shell.h"

int main(int argc, char *argv[]){
	shell_loop();

	//Perform any shutdown/cleanup.

	return EXIT_SUCCESS;
}
