#include "shell.h"

/* Define the maximum number of aliases */
#define MAX_ALIASES 100

/* Struct to hold alias name and value */
typedef struct Alias {
    char *name;
    char *value;
} Alias;

/* Alias array and count */
Alias aliases[MAX_ALIASES];
int alias_count = 0;

/**
 * add_or_update_alias - Adds a new alias or updates an existing one
 * @name: Name of the alias
 * @value: Value of the alias
 */
void add_or_update_alias(char *name, char *value)
{
    int i;

    /* Check if alias already exists, update it */
    for (i = 0; i < alias_count; i++)
    {
        if (strcmp(aliases[i].name, name) == 0)
        {
            free(aliases[i].value);
            aliases[i].value = strdup(value);
            return;
        }
    }

    /* If alias does not exist, add it */
    if (alias_count < MAX_ALIASES)
    {
        aliases[alias_count].name = strdup(name);
        aliases[alias_count].value = strdup(value);
        alias_count++;
    }
    else
    {
        fprintf(stderr, "alias: Maximum number of aliases reached\n");
    }
}

/**
 * print_alias - Prints a single alias in the format name='value'
 * @name: Name of the alias
 */
void print_alias(char *name)
{
    int i;

    for (i = 0; i < alias_count; i++)
    {
        if (strcmp(aliases[i].name, name) == 0)
        {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            return;
        }
    }

    fprintf(stderr, "alias: %s: not found\n", name);
}

/**
 * print_all_aliases - Prints all aliases in the format name='value'
 */
void print_all_aliases(void)
{
    int i;

    for (i = 0; i < alias_count; i++)
    {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

/**
 * handle_alias - Handles the alias built-in command
 * @args: Array of arguments passed to the alias command
 */
void handle_alias(char **args)
{
    int i;

    if (args[1] == NULL)
    {
        /* No argument, print all aliases */
        print_all_aliases();
        return;
    }

    for (i = 1; args[i] != NULL; i++)
    {
        char *arg = args[i];
        char *eq_sign = strchr(arg, '=');

        if (eq_sign != NULL)
        {
            /* Alias assignment */
            *eq_sign = '\0'; /* Split name and value */
            add_or_update_alias(arg, eq_sign + 1);
        }
        else
        {
            /* Print alias by name */
            print_alias(arg);
        }
    }
}
