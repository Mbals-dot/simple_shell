#include "shell.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 *
 * Return: 1 to continue running, 0 to stop.
 */
int execute_command(char *command)
{
    pid_t pid;
    char *argv[2];

    argv[0] = command;
    argv[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return 1;
    }
    if (pid == 0)
    {
        /* Child process */
        if (execve(command, argv, NULL) == -1)
        {
            perror("./hsh");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        wait(NULL);
    }

    return 1;
}
