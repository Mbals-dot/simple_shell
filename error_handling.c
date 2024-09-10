#include "shell.h"

/**
 * get_error - Handles errors and prints error messages.
 * @datash: The shell data structure.
 * @eval: The error code.
 * Return: The error code.
 */
int get_error(data_shell *datash, int eval) {
  char *error;
  // Switch statement to handle different error codes
  switch (eval) {
    case -1:
      // Handle environment variable error
      error = error_env(datash);
      break;
    case 126:
      // Handle permission denied error
      error = error_path_126(datash);
      break;
    case 127:
      // Handle command not found error
      error = error_not_found(datash);
      break;
    case 2:
      // Handle exit or cd command errors
      if (_strcmp("exit", datash->args[0]) == 0)
        error = error_exit_shell(datash);
      else if (_strcmp("cd", datash->args[0]) == 0)
        error = error_get_cd(datash);
      break;
  }
  // Print the error message if it exists
  if (error) {
    write(STDERR_FILENO, error, _strlen(error));
    free(error);
  }
  // Update the shell status with the error code
  datash->status = eval;
  return (eval);
}
