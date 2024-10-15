#include "shell.h"

/**
 * parse_logical_operators - Splits a command line based on logical operators && and ||
 * @line: Input command line
 * Return: Array of commands separated by logical operators
 */
char **parse_logical_operators(char *line)
{
    char **commands = malloc(TOK_BUFSIZE * sizeof(char *));
    int i = 0;
    char *token;

    if (!commands)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /* Tokenize the input based on && or || */
    token = strtok(line, "&& ||");
    while (token != NULL)
    {
        commands[i++] = token;

        if (i >= TOK_BUFSIZE)
        {
            commands = realloc(commands, (i + TOK_BUFSIZE) * sizeof(char *));
            if (!commands)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, "&& ||");
    }

    commands[i] = NULL;
    return commands;
}

/**
 * execute_logical_commands - Executes commands based on logical operators && and ||
 * @commands: Array of commands
 */
void execute_logical_commands(char **commands)
{
    int i = 0, last_status = 0;

    while (commands[i] != NULL)
    {
        char **args = custom_tokenize(commands[i]);

        if (args == NULL || args[0] == NULL)
        {
            free(args);
            continue;
        }

        /* Execute command and capture exit status */
        last_status = execute_command(args, "shell");

        /* Check for && or || and decide whether to proceed */
        if (strcmp(commands[i], "&&") == 0 && last_status != 0)
        {
            /* If && and the previous command failed, skip the next command */
            i += 2;
        }
        else if (strcmp(commands[i], "||") == 0 && last_status == 0)
        {
            /* If || and the previous command succeeded, skip the next command */
            i += 2;
        }
        else
        {
            i++;
        }

        free(args);
    }
}
