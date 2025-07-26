#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "builtin.h"

char *builtin_str[] = {"cd", "exit", "help"};
int (*builtin_func[])(char **) = {
    &shell_cd,
    &shell_exit,
    &shell_help
};

int shell_num_builtins(){
	return sizeof(builtin_str)/sizeof(char *);
}

int shell_cd(char **args){
	if(args[1] == NULL){
		fprintf(stderr, "shell: expected argument to \"cd\"\n");
	}else{
		if(chdir(args[1]) != 0){
			perror("shell");
		}
	}

	return 1;
}

int shell_help(char **args){
	printf("C-Shellion (custom shell in C) implementation\n");
	printf("Type the program name and argumnets, and hit enter. \n");

	for(int i = 0; i < shell_num_builtins(); i++){
		printf("%s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other program\n");

	return 1;
}

int shell_exit(char **args){
	return 0;
}
