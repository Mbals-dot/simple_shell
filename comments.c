#include "shell.h"

/**
 * remove_comments - Removes any comments (everything after a '#') from the input line
 * @line: The input line
 */
void remove_comments(char *line)
{
    char *comment_start = strchr(line, '#');
    if (comment_start != NULL)
    {
        *comment_start = '\0';  /* Truncate the line at the '#' character */
    }
}
