#include "shell.h"

/**
 * is_colon_directory - Checks if the current character is a colon or the end of the path.
 * @path: The path string.
 * @i: The current index in the path string.
 * Return: 1 if the current character is a colon, 0 otherwise.
 */
int is_colon_directory(char *path, int *i) {
  if (path[*i] == ':') return (1);
  while (path[*i] != ':' && path[*i]) {
    *i += 1;
  }
  if (path[*i]) *i += 1;
  return (0);
}

/**
 * find_command - Finds the path to a command.
 * @cmd: The command name.
 * @_environ: The environment variables.
 * Return: The path to the command, or NULL if not found.
 */
char *find_command(char *cmd, char **_environ) {
  char *path, *ptr_path, *token_path, *dir;
  int len_dir, len_cmd, i;
  struct stat st;
  
  // Get the PATH environment variable
  path = _getenv("PATH", _environ);
  
  if (path) {
    // Duplicate the PATH string
    ptr_path = _strdup(path);
    
    // Get the length of the command name
    len_cmd = _strlen(cmd);
    
    // Tokenize the PATH string
    token_path = _strtok(ptr_path, ":");
    
    // Iterate through the directories in the PATH
    i = 0;
    while (token_path != NULL) {
      // Check if the current directory is a colon directory
      if (is_colon_directory(path, &i)) {
        // Check if the command is in the current directory
        if (stat(cmd, &st) == 0) return (cmd);
      }
      
      // Get the length of the current directory
      len_dir = _strlen(token_path);
      
      // Allocate memory for the full path
      dir = malloc(len_dir + len_cmd + 2);
      
      // Construct the full path
      _strcpy(dir, token_path);
      _strcat(dir, "/");
      _strcat(dir, cmd);
      _strcat(dir, "\0");
      
      // Check if the command is in the current directory
      if (stat(dir, &st) == 0) {
        free(ptr_path);
        return (dir);
      }
      
      // Free the memory allocated for the full path
      free(dir);
      
      // Get the next directory in the PATH
      token_path = _strtok(NULL, ":");
    }
    
    // Free the memory allocated for the PATH string
    free(ptr_path);
  }
  
  // Check if the command is in the current directory
  if (stat(cmd, &st) == 0) return (cmd);
  
  return (NULL);
}

/**
 * is_executable_file - Checks if a file is executable.
 * @datash: The shell data structure.
 * Return: The index of the executable file, or -1 if not found.
 */
int is_executable_file(data_shell *datash) {
  struct stat st;
  int i;
  char *input;
  
  // Get the input string
  input = datash->args[0];
  
  // Iterate through the input string
  for (i = 0; input[i]; i++) {
    // Check if the current character is a dot
    if (input[i] == '.') {
      // Check if the next character is a dot
      if (input[i + 1] == '.') return (0);
      // Check if the next character is a slash
      if (input[i + 1] == '/') continue;
      else break;
    }
    // Check if the current character is a slash
    else if (input[i] == '/' && i != 0) {
      // Check if the next character is a dot
      if (input[i + 1] == '.') continue;
      i++;
      break;
    }
    else break;
  }
  
  // Check if the file is executable
  if (i == 0) return (0);
  if (stat(input + i, &st) == 0) {
    return (i);
  }
  
  // Print an error message
  get_error(datash, 127);
  
  return (-1);
}

/**
 * check_command_error - Checks for errors in the command.
 * @dir: The directory of the command.
 * @datash: The shell data structure.
 * Return: 1 if an error occurred, 0 otherwise.
 */
int check_command_error(char *dir, data_shell *datash) {
  // Check if the directory is NULL
  if
