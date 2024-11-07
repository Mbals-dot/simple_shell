#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_command - Reads a command from the user.
 *
 * Return: Pointer to the command string.
 */
char *read_command(void)
{
    char *command = NULL;
    size_t len = 0;

    if (getline(&command, &len, stdin) == -1)
    {
        free(command);
        return NULL;
    }

    /* Remove the newline character at the end */
    command[strcspn(command, "\n")] = '\0';
    return command;
}
