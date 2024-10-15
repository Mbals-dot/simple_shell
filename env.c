#include "shell.h"

/**
 * print_env - Prints the current environment
 */
void print_env(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}
