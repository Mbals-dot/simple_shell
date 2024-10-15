#include "shell.h"

/**
 * execute_command - Executes the command passed as argument
 * @args: Array of arguments
 * @shell_name: Name of the shell (argv[0])
 * Return: 1 on success, -1 on error
 */
int execute_command(char **args, char *shell_name)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (-1);
    }
    
    if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
        {
            fprintf(stderr, "%s: %s: command not found\n", shell_name, args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    return (1);
}
