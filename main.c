#include "shell.h"

/**
 * free_data - Frees the memory allocated for the shell's data structure
 * @datash: Pointer to the shell data structure
 * Return: None
 */
void free_data(data_shell *datash) {
    unsigned int i;
    for (i = 0; datash->_environ[i]; i++) {
        free(datash->_environ[i]);
    }
    free(datash->_environ);
    free(datash->pid);
}

/**
 * set_data - Initializes the shell's data structure
 * @datash: Pointer to the shell data structure
 * @av: Array of command-line arguments
 * Return: None
 */
void set_data(data_shell *datash, char **av) {
    unsigned int i;
    datash->av = av;
    datash->input = NULL;
    datash->args = NULL;
    datash->status = 0;
    datash->counter = 1;
    for (i = 0; environ[i]; i++) ;
    datash->_environ = malloc(sizeof(char *) * (i + 1));
    for (i = 0; environ[i]; i++) {
        datash->_environ[i] = _strdup(environ[i]);
    }
    datash->_environ[i] = NULL;
    datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of the program
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments
 * Return: Exit status of the shell
 */
int main(int ac, char **av) {
    data_shell datash;
    (void) ac;
    signal(SIGINT, get_sigint);
    set_data(&datash, av);
    shell_loop(&datash);
    free_data(&datash);
    if (datash.status < 0) return (255);
    return (datash.status);
}
