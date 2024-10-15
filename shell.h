#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/* Function prototypes */
int execute_command(char **args, char *shell_name);
char **custom_tokenize(char *line);
void replace_variables(char **line, int status);
void remove_comments(char *line);
char **parse_logical_operators(char *line);
void execute_logical_commands(char **commands);
void print_env(void);
void handle_exit(char **args);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
void handle_cd(char **args);
void handle_alias(char **args);
int _atoi(char *str);

#endif /* SHELL_H */
