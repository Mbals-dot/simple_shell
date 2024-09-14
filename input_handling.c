#include "shell.h"

/**
 * read_input_line - Reads a line of input from the user.
 * @i_eof: A pointer to an integer to store the EOF status.
 * Return: The input line, or NULL on error.
 */
char *read_input_line(int *i_eof) {
  char *input_line = NULL; // The input line buffer
  size_t bufsize = 0; // The initial buffer size

  // Read a line of input from the user
  *i_eof = getline(&input_line, &bufsize, stdin);

  return (input_line);
}
