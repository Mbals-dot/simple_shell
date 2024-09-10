// Include the shell header file
#include "shell.h"

/**
 * cmp_env_name - Compares an environment name with a given string.
 * @nenv: The environment name.
 * @name: The given string.
 * Return: The length of the matched string, or 0 if no match.
 */
int cmp_env_name(const char *nenv, const char *name) {
  int i;
  // Loop through the environment name until the '=' character is found
  for (i = 0; nenv[i] != '='; i++) {
    // If the characters at the current index do not match, return 0
    if (nenv[i] != name[i])
      return (0);
  }
  // Return the length of the matched string
  return (i + 1);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 * @_environ: The environment variables array.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name, char **_environ) {
  char *ptr_env;
  int i, mov;
  // Initialize the return value to NULL
  ptr_env = NULL;
  mov = 0;
  // Loop through the environment variables array
  for (i = 0; _environ[i]; i++) {
    // Compare the current environment variable name with the given name
    mov = cmp_env_name(_environ[i], name);
    // If a match is found, update the return value and break the loop
    if (mov) {
      ptr_env = _environ[i];
      break;
    }
  }
  // Return the value of the environment variable
  return (ptr_env + mov);
}

/**
 * _env - Prints the environment variables.
 * @datash: The shell data structure.
 * Return: 1 on success.
 */
int _env(data_shell *datash) {
  int i, j;
  // Loop through the environment variables array
  for (i = 0; datash->_environ[i]; i++) {
    // Loop through the current environment variable string
    for (j = 0; datash->_environ[i][j]; j++)
      ;
    // Print the environment variable string
    write(STDOUT_FILENO, datash->_environ[i], j);
    write(STDOUT_FILENO, "\n", 1);
  }
  // Set the shell status to 0
  datash->status = 0;
  return (1);
}
