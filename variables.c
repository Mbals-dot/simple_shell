#include "shell.h"

/**
 * replace_variables - Replaces variables like $? and $$ and environment variables in the command line
 * @line: The command line to process
 * @status: The last exit status to replace $?
 */
void replace_variables(char **line, int status)
{
    char *new_line = malloc(strlen(*line) + 100); /* Allocate enough space */
    char *ptr = *line;
    char buffer[10];
    pid_t pid = getpid();
    int i = 0, j = 0;
    char *env_value;  /* Declare env_value at the top of the block */

    if (!new_line)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (ptr[i])
    {
        if (ptr[i] == '$' && ptr[i + 1])
        {
            if (ptr[i + 1] == '?')
            {
                /* Replace $? with the status */
                sprintf(buffer, "%d", status);
                strcat(new_line, buffer);
                i += 2;
                continue;
            }
            else if (ptr[i + 1] == '$')
            {
                /* Replace $$ with the shell's PID */
                sprintf(buffer, "%d", pid);
                strcat(new_line, buffer);
                i += 2;
                continue;
            }
            else
            {
                /* Replace $VAR with its value */
                char var_name[100];
                int k = 0;

                i++; /* Skip $ */
                while (ptr[i] && (ptr[i] != ' ' && ptr[i] != '\t' && ptr[i] != '\n'))
                {
                    var_name[k++] = ptr[i++];
                }
                var_name[k] = '\0';

                env_value = getenv(var_name);
                if (env_value)
                {
                    strcat(new_line, env_value);
                }
                else
                {
                    strcat(new_line, ""); /* Variable not found, replace with empty string */
                }
                continue;
            }
        }
        else
        {
            /* Just copy the character */
            new_line[j++] = ptr[i++];
        }
    }

    new_line[j] = '\0';

    /* Replace the original line */
    free(*line);
    *line = strdup(new_line);
    free(new_line);
}
