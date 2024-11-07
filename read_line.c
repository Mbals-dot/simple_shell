#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

char *read_line(void) {
    char *line = NULL;
    size_t bufsize = 0; /* Buffer size for getline */

    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS); /* End of file reached */
        } else {
            perror("read_line");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}
