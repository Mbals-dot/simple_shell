#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>  /* Include POSIX functions like fork, execve, and wait */

#define BUFFER_SIZE 1024
#define DELIMITERS " \t\r\n\a:"

/* Function prototypes */
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
char *find_command_path(const char *command);
char *read_line(void);

#endif /* SHELL_H */
