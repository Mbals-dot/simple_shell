#include "shell.h"

/**
 * _atoi - Converts a string to an integer
 * @str: String to convert
 * Return: The integer value of the string, or -1 if the string is not a valid integer
 */
int _atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);  /* Not a valid number */
        result = result * 10 + (str[i] - '0');
    }

    return (result * sign);
}
