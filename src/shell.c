#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"
#include "builtin.h"

#define SHELL_RL_BUFSIZE 1024
#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\n\r\a"

void shell_loop(void){
	char *line;
	char **args;
	int status;

	do{
		printf("c-shellion> ");

		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	}while (status);
}

int shell_execute(char **args){
	if(args[0] == NULL){
		return 1;
	}

	for(int i = 0; i < shell_num_builtins(); i++){
		if(strcmp(args[0], builtin_str[i]) == 0){
			return (*builtin_func[i])(args);
		}
	}

	return shell_launch(args);
}

int shell_launch(char **args){
    pid_t pid, wpid;
    int status;

    pid = fork();

    if(pid == 0){
        if (execv(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    }else if(pid < 0){
       perror("shell");
    }else{
        do {
             wpid = waitpid(pid, &status, WUNTRACED);
        }while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

char **shell_split_line(char *line){
	int bufsize = SHELL_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if(!tokens){
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, SHELL_TOK_DELIM);

	while(token != NULL){
		tokens[position] = token;
		position++;

		if(position >= bufsize){
			bufsize += SHELL_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if(!tokens){
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, SHELL_TOK_DELIM);
	}

	tokens[position] = NULL;
	return tokens;
}

char *shell_read_line(void){
	int bufsize = SHELL_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if(!buffer){
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		c = getchar();

		if(c == EOF || c == '\n'){
			buffer[position] = '\0';

			return buffer;
		}else{
			buffer[position] = c;
		}

		position++;

		if(position >= bufsize){
			bufsize += SHELL_RL_BUFSIZE;

			buffer = realloc(buffer, bufsize);

			if(!buffer){
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
