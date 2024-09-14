#include "shell.h"

/**
 * handle_exit_command - Handles the exit command.
 * @datash: The shell data structure.
 * Return: 0 on success, 1 on error.
 */
int handle_exit_command(data_shell *datash) {
  unsigned int exit_status;
  int is_valid;

  // Check if an exit status was provided
  if (datash->args[1] != NULL) {
    // Validate the exit status
    is_valid = validate_exit_status(datash->args[1], &exit_status);

    // Check for errors in the exit status
    if (!is_valid) {
      // Print an error message
      get_error(datash, 2);
      datash->status = 2;
      return (1);
    }

    // Set the shell status to the exit status
    datash->status = (exit_status % 256);
  }

  return (0);
}

/**
 * validate_exit_status - Validates the exit status.
 * @status_str: The exit status string.
 * @exit_status: A pointer to store the validated exit status.
 * Return: 1 if valid, 0 otherwise.
 */
int validate_exit_status(char *status_str, unsigned int *exit_status) {
  int is_digit = _isdigit(status_str);
  int str_len = _strlen(status_str);
  unsigned int status = _atoi(status_str);
  int big_number = status > (unsigned int)INT_MAX;

  // Check if the exit status is valid
  if (!is_digit || str_len > 10 || big_number) {
    return (0);
  }

  *exit_status = status;
  return (1);
}
