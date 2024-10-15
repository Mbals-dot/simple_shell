#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    char **args;
    size_t len = 0;
    ssize_t nread;
    int status = 0;  /* Last exit status */
    FILE *input_stream = stdin;  /* Default input is stdin */

    if (argc == 2)
    {
        /* Open the file if a filename is provided as an argument */
        input_stream = fopen(argv[1], "r");
        if (input_stream == NULL)
        {
            perror(argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    
    while ((nread = getline(&line, &len, input_stream)) != -1)
    {
        line[nread - 1] = '\0';  /* Remove newline character */

        /* Handle comments by truncating the line at the first '#' */
        remove_comments(line);

        /* Handle variable replacements */
        replace_variables(&line, status);

        /* Tokenize and execute command */
        args = custom_tokenize(line);
        if (args == NULL || args[0] == NULL)
        {
            free(args);
            continue;
        }

        status = execute_command(args, argv[0]);

        free(args);
    }

    free(line);
    
    /* Close the file if it was opened */
    if (argc == 2)
        fclose(input_stream);

    return (status);
}
