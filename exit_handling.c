#include "shell.h"

/**
 * handle_exit_command - Handles the exit command.
 * @datash: The shell data structure.
 * Return: 0 on success, 1 on error.
 */
int handle_exit_command(data_shell *datash) {
  unsigned int exit_status;
  int is_digit;
  int str_len;
  int big_number;

  // Check if an exit status was provided
  if (datash->args[1] != NULL) {
    // Convert the exit status to an integer
    exit_status = _atoi(datash->args[1]);

    // Check if the exit status is a digit
    is_digit = _isdigit(datash->args[1]);

    // Get the length of the exit status string
    str_len = _strlen(datash->args[1]);

    // Check if the exit status is too large
    big_number = exit_status > (unsigned int)INT_MAX;

    // Check for errors in the exit status
    if (!is_digit || str_len > 10 || big_number) {
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
