#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>  /* Include for fork, execve, and wait */

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execve(args[0], args, NULL) == -1) {
            perror("execve error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Forking error */
        perror("fork error");
    } else {
        /* Parent process */
        wait(&status);
    }
    return status;
}
