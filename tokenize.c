#include "shell.h"

/**
 * tokenize - Tokenizes the input string into arguments
 * @line: Input line
 * Return: Array of tokens (command and arguments)
 */
char **tokenize(char *line)
{
    int bufsize = TOK_BUFSIZE, i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[i] = token;
        i++;

        if (i >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[i] = NULL;

    return (tokens);
}
