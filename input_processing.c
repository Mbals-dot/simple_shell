#include "shell.h"

/**
 * remove_comment - Removes the comment from the input string.
 * @input: The input string.
 * Return: The input string without the comment.
 */
char *remove_comment(char *input) {
  int i, comment_start;
  comment_start = 0;

  // Iterate through the input string
  for (i = 0; input[i]; i++) {
    // Check if the character is a comment symbol
    if (input[i] == '#') {
      // If the comment symbol is at the beginning of the string, return NULL
      if (i == 0) {
        free(input);
        return (NULL);
      }
      // Check if the character before the comment symbol is a space, tab, or semicolon
      if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
        comment_start = i;
    }
  }

  // If a comment was found, reallocate the string and remove the comment
  if (comment_start != 0) {
    input = _realloc(input, i, comment_start + 1);
    input[comment_start] = '\0';
  }

  return (input);
}

/**
 * shell_loop - The main loop of the shell.
 * @datash: The shell data structure.
 */
void shell_loop(data_shell *datash) {
  int loop, i_eof;
  char *input;

  loop = 1;
  while (loop == 1) {
    // Print the prompt
    write(STDIN_FILENO, "^-^ ", 4);

    // Read the input
    input = read_line(&i_eof);

    // Check if the input is not EOF
    if (i_eof != -1) {
      // Remove the comment from the input
      input = remove_comment(input);

      // Check if the input is not NULL
      if (input == NULL)
        continue;

      // Check for syntax errors
      if (check_syntax_error(datash, input) == 1) {
        datash->status = 2;
        free(input);
        continue;
      }

      // Replace variables in the input
      input = rep_var(input, datash);

      // Split the input into commands
      loop = split_commands(datash, input);

      // Increment the command counter
      datash->counter += 1;

      // Free the input
      free(input);
    } else {
      // If EOF is reached, exit the loop
      loop = 0;
      free(input);
    }
  }
}
