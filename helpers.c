#include "shell.h"

/**
 * print_error - Prints an error message with the command name.
 * @command: The command that caused the error.
 */
void print_error(char *command)
{
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, ": not found\n", 12);
}
