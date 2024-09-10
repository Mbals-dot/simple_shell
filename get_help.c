#include "shell.h"

/**
 * display_help - Displays help information for shell commands.
 * @datash: The shell data structure.
 * Return: 1 on success.
 */
int display_help(data_shell *datash) {
  // Check if the user requested general help
  if (datash->args[1] == 0) {
    aux_help_general(); // Display general help
  } 
  // Check if the user requested help for a specific command
  else if (_strcmp(datash->args[1], "setenv") == 0) {
    aux_help_setenv(); // Display help for setenv command
  } else if (_strcmp(datash->args[1], "env") == 0) {
    aux_help_env(); // Display help for env command
  } else if (_strcmp(datash->args[1], "unsetenv") == 0) {
    aux_help_unsetenv(); // Display help for unsetenv command
  } else if (_strcmp(datash->args[1], "help") == 0) {
    aux_help(); // Display help for help command
  } else if (_strcmp(datash->args[1], "exit") == 0) {
    aux_help_exit(); // Display help for exit command
  } else if (_strcmp(datash->args[1], "cd") == 0) {
    aux_help_cd(); // Display help for cd command
  } else if (_strcmp(datash->args[1], "alias") == 0) {
    aux_help_alias(); // Display help for alias command
  } 
  // If the user requested help for an invalid command, display an error message
  else {
    write(STDERR_FILENO, datash->args[0], _strlen(datash->args[0]));
  }
  
  // Set the shell status to 0
  datash->status = 0;
  
  return (1);
}

