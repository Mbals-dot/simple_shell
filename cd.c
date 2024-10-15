#include "shell.h"
#include <limits.h>  /* Include limits.h for PATH_MAX */

/**
 * handle_cd - Handles the built-in cd command
 * @args: Array of arguments passed to cd
 */
void handle_cd(char **args)
{
    char *dir;
    char *oldpwd = getenv("OLDPWD");
    char cwd[PATH_MAX];  /* PATH_MAX is defined here after including limits.h */

    if (args[1] == NULL)
    {
        /* If no argument is given, change to the HOME directory */
        dir = getenv("HOME");
        if (dir == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return;
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        /* If "cd -" is given, change to the previous directory (OLDPWD) */
        if (oldpwd == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return;
        }
        dir = oldpwd;
        printf("%s\n", dir);  /* Print the directory we are changing to */
    }
    else
    {
        /* Otherwise, use the directory specified by the user */
        dir = args[1];
    }

    /* Change the directory */
    if (chdir(dir) == -1)
    {
        perror("cd");
        return;
    }

    /* Update the PWD and OLDPWD environment variables */
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("OLDPWD", getenv("PWD"), 1);  /* Update OLDPWD */
        setenv("PWD", cwd, 1);               /* Update PWD */
    }
    else
    {
        perror("getcwd");
    }
}
