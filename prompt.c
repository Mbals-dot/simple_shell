#include "shell.h"
#include <unistd.h>  /* Include for write and STDOUT_FILENO */

void display_prompt(void) {
    write(STDOUT_FILENO, "$ ", 2);
}
