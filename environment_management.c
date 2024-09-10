// Include the shell header file
#include "shell.h"

/**
 * copy_info - Copies environment variable information.
 * @name: The environment variable name.
 * @value: The environment variable value.
 * Return: A new string containing the copied information.
 */
char *copy_info(char *name, char *value) {
  char *new;
  int len_name, len_value, len;
  // Calculate the length of the new string
  len_name = _strlen(name);
  len_value = _strlen(value);
  len = len_name + len_value + 2;
  // Allocate memory for the new string
  new = malloc(sizeof(char) * (len));
  // Copy the environment variable information
  _strcpy(new, name);
  _strcat(new, "=");
  _strcat(new, value);
  _strcat(new, "\0");
  return (new);
}

/**
 * set_env - Sets an environment variable.
 * @name: The environment variable name.
 * @value: The environment variable value.
 * @datash: The shell data structure.
 * Return: None
 */
void set_env(char *name, char *value, data_shell *datash) {
  int i;
  char *var_env, *name_env;
  // Loop through the environment variables array
  for (i = 0; datash->_environ[i]; i++) {
    // Duplicate the current environment variable string
    var_env = _strdup(datash->_environ[i]);
    // Tokenize the environment variable string
    name_env = _strtok(var_env, "=");
    // Check if the environment variable name matches
    if (_strcmp(name_env, name) == 0) {
      // Free the old environment variable string
      free(datash->_environ[i]);
      // Set the new environment variable string
      datash->_environ[i] = copy_info(name_env, value);
      free(var_env);
      return;
    }
    free(var_env);
  }
  // Reallocate memory for the environment variables array
  datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
  // Set the new environment variable string
  datash->_environ[i] = copy_info(name, value);
  datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - Sets an environment variable.
 * @datash: The shell data structure.
 * Return: 1 on success.
 */
int _setenv(data_shell *datash) {
  // Check if the required arguments are provided
  if (datash->args[1] == NULL || datash->args[2] == NULL) {
    get_error(datash, -1);
    return (1);
  }
  // Set the environment variable
  set_env(datash->args[1], datash->args[2], datash);
  return (1);
}

/**
 * _unsetenv - Unsets an environment variable.
 * @datash: The shell data structure.
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash) {
  char **realloc_environ;
  char *var_env, *name_env;
  int i, j, k;
  // Check if the required argument is provided
  if (datash->args[1] == NULL) {
    get_error(datash, -1);
    return (1);
  }
  // Initialize the index of the environment variable to be unset
  k = -1;
  // Loop through the environment variables array
  for (i = 0; datash->_environ[i]; i++) {
    // Duplicate the current environment variable string
    var_env = _strdup(datash->_environ[i]);
    // Tokenize the environment variable string
    name_env = _strtok(var_env, "=");
    // Check if the environment variable name matches
    if (_strcmp(name_env, datash->args[1]) == 0) {
      // Update the index of the environment variable to be unset
      k = i;
    }
    free(var_env);
  }
  // Check if the environment variable was found
  if (k == -1) {
    get_error(datash, -1);
    return (1);
  }
  // Reallocate memory for the environment variables array
  realloc_environ = malloc(sizeof(char *) * (i));
  // Copy the environment variables array, excluding the one to be unset
  for (i = j = 0; datash->_environ[i]; i++) {
    if (i != k) {
      realloc_environ[j] = datash->_environ[i];
      j++;
    }
  }
  realloc_environ[j] = NULL;
  // Free the old environment variable string
