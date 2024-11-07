#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line;
    char **args;
    int status = 1;

    while (status)
    {
        /* Display prompt */
        display_prompt();

        /* Read line */
        line = read_line();
        if (!line)
        {
            perror("Error reading line");
            exit(EXIT_FAILURE);
        }

        /* Check for the 'exit' command */
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        /* Parse line and execute command */
        args = parse_line(line);
        if (args[0] != NULL)
        {
            status = execute_command(args);
        }

        /* Free memory */
        free(line);
        free(args);
    }

    return 0;
}
