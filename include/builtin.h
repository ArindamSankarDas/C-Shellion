#ifndef BUILTIN_H
#define BUILTIN_H

int shell_cd(char **args);
int shell_pwd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
int shell_history(char **args);
int shell_num_builtins(void);

char *join_args(char **args);

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

#endif
