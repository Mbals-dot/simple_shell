#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define DELIM " \t\r\n\a"

char *read_line(void);
char **split_line(char *line);
int execute(char **args);

#endif /* SHELL_H */
