#include "shell.h"

/**
 * print_help_message - Prints the help message for the help command.
 */
void print_help_message(void) {
  char *message = "help: help [-dms] [pattern ...]\n";
  write(STDOUT_FILENO, message, _strlen(message));
  message = "\tDisplay information about builtin commands.\n";
  write(STDOUT_FILENO, message, _strlen(message));
  message = "Displays brief summaries of builtin commands.\n";
  write(STDOUT_FILENO, message, _strlen(message));
}

/**
 * print_alias_help_message - Prints the help message for the alias command.
 */
void print_alias_help_message(void) {
  char *message = "alias: alias [-p] [name[=value]...]\n";
  write(STDOUT_FILENO, message, _strlen(message));
  message = "\tDefine or display aliases.\n";
  write(STDOUT_FILENO, message, _strlen(message));
}

/**
 * print_cd_help_message - Prints the help message for the cd command.
 */
void print_cd_help_message(void) {
  char *message = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
  write(STDOUT_FILENO, message, _strlen(message));
  message = "\tChange the shell working directory.\n";
  write(STDOUT_FILENO, message, _strlen(message));
}
