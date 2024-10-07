#include "shell.h"

/**
 * strcat_cd - Concatenates error messages for cd command.
 * @datash: The shell data structure.
 * @msg: The error message.
 * @error: The error string.
 * @ver_str: The version string.
 * Return: The concatenated error string.
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str) {
  char *illegal_flag;
  // Concatenate the error message
  _strcpy(error, datash->av[0]);
  _strcat(error, ": ");
  _strcat(error, ver_str);
  _strcat(error, ": ");
  _strcat(error, datash->args[0]);
  _strcat(error, msg);
  // Check for illegal flag
  if (datash->args[1][0] == '-') {
    illegal_flag = malloc(3);
    illegal_flag[0] = '-';
    illegal_flag[1] = datash->args[1][1];
    illegal_flag[2] = '\0';
    _strcat(error, illegal_flag);
    free(illegal_flag);
  } else {
    _strcat(error, datash->args[1]);
  }
  _strcat(error, "\n");
  _strcat(error, "\0");
  return (error);
}

/**
 * error_get_cd - Generates error message for cd command.
 * @datash: The shell data structure.
 * Return: The error message string.
 */
char *error_get_cd(data_shell *datash) {
  int length, len_id;
  char *error, *ver_str, *msg;
  // Get the version string
  ver_str = aux_itoa(datash->counter);
  // Check for illegal option or invalid directory
  if (datash->args[1][0] == '-') {
    msg = ": Illegal option ";
    len_id = 2;
  } else {
    msg = ": can't cd to ";
    len_id = _strlen(datash->args[1]);
  }
  // Calculate the length of the error message
  length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
  length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
  // Allocate memory for the error message
  error = malloc(sizeof(char) * (length + 1));
  if (error == 0) {
    free(ver_str);
    return (NULL);
  }
  // Concatenate the error message
  error = strcat_cd(datash, msg, error, ver_str);
  free(ver_str);
  return (error);
}

/**
 * error_not_found - Generates error message for command not found.
 * @datash: The shell data structure.
 * Return: The error message string.
 */
char *error_not_found(data_shell *datash) {
  int length;
  char *error;
  char *ver_str;
  // Get the version string
  ver_str = aux_itoa(datash->counter);
  // Calculate the length of the error message
  length = _strlen(datash->av[0]) + _strlen(ver_str);
  length += _strlen(datash->args[0]) + 16;
  // Allocate memory for the error message
  error = malloc(sizeof(char) * (length + 1));
  if (error == 0) {
    free(error);
    free(ver_str);
    return (NULL);
  }
  // Concatenate the error message
  _strcpy(error, datash->av[0]);
  _strcat(error, ": ");
  _strcat(error, ver_str);
  _strcat(error, ": ");
  _strcat(error, datash->args[0]);
  _strcat(error, ": not found\n");
  _strcat(error, "\0");
  free(ver_str);
  return (error);
}

/**
 * error_exit_shell - Generates error message for exit command.
 * @datash: The shell data structure.
 * Return: The error message string.
 */
char *error_exit_shell(data_shell *datash) {
  int length;
  char *error;
  char *ver_str;
  // Get the version string
  ver_str = aux_itoa(datash->counter);
  // Calculate the length of the error message
  length = _strlen(datash->av[0]) + _strlen(ver_str);
  length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
  // Allocate memory for the error message
  error = malloc(sizeof(char) * (length + 1));
  if (error == 0) {
    free(ver_str);
    return (NULL);
}
} 
// Concatenate
