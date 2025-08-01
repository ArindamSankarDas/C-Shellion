#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "builtin.h"

#define MAX_HISTORY_COUNT 100

char *builtin_str[] = {"cd", "exit", "pwd", "history", "help"};
int (*builtin_func[])(char **) = {
    &shell_cd,
    &shell_exit,
    &shell_pwd,
    &shell_history,
    &shell_help
};

char *join_args(char **args){
   int total_size = 0;

   for (int i = 0; args[i] != NULL; i++) {
      total_size += strlen(args[i]) + 1;
   }

   char *result = malloc(total_size * sizeof(char));

   if (!result) return NULL;

   result[0] = '\0';

   for (int i = 0; args[i] != NULL; i++) {
       strcat(result, args[i]);

       if (args[i + 1] != NULL) {
           strcat(result, " ");
       }
   }

   return result;
}

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

int shell_pwd(char **args){
   char currentPath[PATH_MAX];

   if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
       printf("Current working directory: %s \n", currentPath);
   }else {
       perror("getcwd");
       return EXIT_FAILURE;
   }

   return EXIT_FAILURE;
}

int shell_history(char **args){
    static char *historyList[MAX_HISTORY_COUNT];

    static int currentCount = 0;

    if (strcmp(args[0], "history") == 0) {
        for (int i = 0; i < MAX_HISTORY_COUNT; i++) {
            printf("%d. %s\n", i + 1, historyList[i]);

            if (historyList[i + 1] == NULL) {
                break;
            }
        }

        return EXIT_SUCCESS;
    }else{
        if(currentCount < MAX_HISTORY_COUNT){
            historyList[currentCount] = strdup(join_args(args));
            currentCount++;
        }

        return EXIT_SUCCESS;
    }
}

int shell_help(char **args){
	printf("C-Shellion (custom shell in C) implementation, available commands: \n");

	for(int i = 0; i < shell_num_builtins(); i++){
		printf("%s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other program\n");

	return 1;
}

int shell_exit(char **args){
	return 0;
}
