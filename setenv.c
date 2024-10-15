#include "shell.h"

/**
 * handle_setenv - Handles the setenv command
 * @args: Array of arguments passed to setenv
 * 
 * Command syntax: setenv VARIABLE VALUE
 */
void handle_setenv(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "setenv: Invalid syntax. Usage: setenv VARIABLE VALUE\n");
        return;
    }

    if (setenv(args[1], args[2], 1) == -1)
    {
        perror("setenv");
    }
}

/**
 * handle_unsetenv - Handles the unsetenv command
 * @args: Array of arguments passed to unsetenv
 * 
 * Command syntax: unsetenv VARIABLE
 */
void handle_unsetenv(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "unsetenv: Invalid syntax. Usage: unsetenv VARIABLE\n");
        return;
    }

    if (unsetenv(args[1]) == -1)
    {
        perror("unsetenv");
    }
}
