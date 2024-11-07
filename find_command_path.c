#include "shell.h"
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *find_command_path(const char *command) {
    char *path = getenv("PATH");
    char *token;
    struct stat st;

    if (!path) return NULL;

    token = strtok(path, ":");
    while (token != NULL) {
        char *command_path = malloc(strlen(token) + strlen(command) + 2);
        if (!command_path) return NULL;

        strcpy(command_path, token);
        strcat(command_path, "/");
        strcat(command_path, command);

        if (stat(command_path, &st) == 0) {
            return command_path;
        }

        free(command_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}
