#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "builtin.h"

char *builtin_str[] = {"cd", "exit", "help"};
int (*builtin_func[])(char **) = {
    &lsh_exit,
    &lsh_cd,
    &lsh_help
};

int lsh_num_builtins(){
	return sizeof(builtin_str)/sizeof(char *);
}

int lsh_cd(char **args){
	if(args[1] == NULL){
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}else{
		if(chdir(args[1]) != 0){
			perror("lsh");
		}
	}

	return 1;
}

int lsh_help(char **args){
	printf("C-Shellion (custom shell in C) implementation\n");
	printf("Type the program name and argumnets, and hit enter. \n");

	for(int i = 0; i < lsh_num_builtins(); i++){
		printf("%s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other program\n");

	return 1;
}

int lsh_exit(char **args){
	return 0;
}
