#include "shell.h"

/**
 * display_help - Displays help information for shell commands.
 * @datash: The shell data structure.
 * Return: 1 on success.
 */
int display_help(data_shell *datash) {
  // Check if the user requested general help
  if (datash->args[1] == 0) {
    aux_display_general_help();
  } 
  // Check if the user requested help for a specific command
  else if (_strcmp(datash->args[1], "setenv") == 0) {
    aux_display_setenv_help();
  } else if (_strcmp(datash->args[1], "env") == 0) {
    aux_display_env_help();
  } else if (_strcmp(datash->args[1], "unsetenv") == 0) {
    aux_display_unsetenv_help();
  } else if (_strcmp(datash->args[1], "help") == 0) {
    aux_display_help_help();
  } else if (_strcmp(datash->args[1], "exit") == 0) {
    aux_display_exit_help();
  } else if (_strcmp(datash->args[1], "cd") == 0) {
    aux_display_cd_help();
  } else if (_strcmp(datash->args[1], "alias") == 0) {
    aux_display_alias_help();
  } 
  // If the user requested help for an invalid command, display an error message
  else {
    write(STDERR_FILENO, datash->args[0], _strlen(datash->args[0]));
  }
  
  // Set the shell status to 0
  datash->status = 0;
  
  return (1);
}
