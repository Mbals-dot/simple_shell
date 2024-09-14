#include "shell.h"

/**
 * get_environment_error_message - Generates an error message for environment variable errors.
 * @datash: The shell data structure.
 * Return: The error message string.
 */
char *get_environment_error_message(data_shell *datash) {
  int length;
  char *error;
  char *ver_str;
  char *msg;
  
  // Get the version string
  ver_str = aux_itoa(datash->counter);
  
  // Define the error message
  msg = ": Unable to add/remove from environment\n";
  
  // Calculate the length of the error message
  length = _strlen(datash->av[0]) + _strlen(ver_str);
  length += _strlen(datash->args[0]) + _strlen(msg) + 4;
  
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
  _strcat(error, msg);
  _strcat(error, "\0");
  
  free(ver_str);
  return (error);
}

/**
 * get_permission_denied_error_message - Generates an error message for permission denied errors.
 * @datash: The shell data structure.
 * Return: The error message string.
 */
char *get_permission_denied_error_message(data_shell *datash) {
  int length;
  char *ver_str;
  char *error;
  
  // Get the version string
  ver_str = aux_itoa(datash->counter);
  
  // Calculate the length of the error message
  length = _strlen(datash->av[0]) + _strlen(ver_str);
  length += _strlen(datash->args[0]) + 24;
  
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
  _strcat(error, ": Permission denied\n");
  _strcat(error, "\0");
  
  free(ver_str);
  return (error);
}

