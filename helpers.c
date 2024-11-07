#include "shell.h"
#include <unistd.h>  /* Include for write and STDERR_FILENO */

void print_error(char *command) {
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, ": command not found\n", 20);
}
