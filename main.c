#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
    char *command;
    int status = 1;

    while (status)
    {
        display_prompt();
        command = read_command();
        if (command == NULL)
        {
            /* Handle end of file (Ctrl+D) */
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        if (strcmp(command, "exit") == 0)
        {
            free(command);
            break;
        }
        status = execute_command(command);
        free(command);
    }

    return 0;
}
