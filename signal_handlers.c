include "shell.h"

/**
 * handle_sigint - Handles the SIGINT signal (Ctrl+C).
 * @sig: The signal number (not used in this implementation).
 * Return: None.
 */
void handle_sigint(int sig) {
  // Ignore the signal number parameter
  (void)sig;
  
  // Write a message to STDOUT to indicate that the signal was caught
  write(STDOUT_FILENO, "\n^-^ ", 5);
}
