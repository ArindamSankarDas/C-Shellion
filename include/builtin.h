#ifndef BUILTIN_H
#define BUILTIN_H

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_num_builtins(void);

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

#endif
