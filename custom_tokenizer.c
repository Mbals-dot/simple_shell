#include "shell.h"

/**
 * custom_tokenize - Tokenizes the input string without using strtok
 * @line: Input string
 * Return: Array of tokens (words)
 */
char **custom_tokenize(char *line)
{
    int bufsize = TOK_BUFSIZE, i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token_start = NULL;
    int in_token = 0, j = 0;

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; line[i] != '\0'; i++)
    {
        /* Check if the character is a delimiter */
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            if (in_token)
            {
                tokens[j] = malloc(i - (token_start - line) + 1);
                if (!tokens[j])
                {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }
                strncpy(tokens[j], token_start, i - (token_start - line));
                tokens[j][i - (token_start - line)] = '\0';
                j++;
                in_token = 0;
            }
        }
        else
        {
            /* Start of a new token */
            if (!in_token)
            {
                token_start = &line[i];
                in_token = 1;
            }
        }

        /* Resize tokens array if necessary */
        if (j >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Handle the last token if the string didn't end with a delimiter */
    if (in_token)
    {
        tokens[j] = malloc(i - (token_start - line) + 1);
        if (!tokens[j])
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strncpy(tokens[j], token_start, i - (token_start - line));
        tokens[j][i - (token_start - line)] = '\0';
        j++;
    }

    tokens[j] = NULL;  /* Null-terminate the array of tokens */
    return tokens;
}
