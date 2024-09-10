#include "shell.h"

/**
 * check_environment_variable - Checks if a string matches an environment variable.
 * @h: The head of the r_var linked list.
 * @in: The input string.
 * @data: The shell data structure.
 * Return: None.
 */
void check_environment_variable(r_var **h, char *in, data_shell *data) {
  int row, chr, j, lval;
  char **_envr;
  
  // Get the environment variables
  _envr = data->_environ;
  
  // Iterate through the environment variables
  for (row = 0; _envr[row]; row++) {
    for (j = 1, chr = 0; _envr[row][chr]; chr++) {
      if (_envr[row][chr] == '=') {
        lval = _strlen(_envr[row] + chr + 1);
        add_rvar_node(h, j, _envr[row] + chr + 1, lval);
        return;
      }
      if (in[j] == _envr[row][chr]) j++;
      else break;
    }
  }
  
  // Handle cases where the input string does not match an environment variable
  for (j = 0; in[j]; j++) {
    if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n') break;
  }
  add_rvar_node(h, j, NULL, 0);
}

/**
 * check_variables - Checks for special variables in the input string.
 * @h: The head of the r_var linked list.
 * @in: The input string.
 * @st: The status string.
 * @data: The shell data structure.
 * Return: The length of the input string.
 */
int check_variables(r_var **h, char *in, char *st, data_shell *data) {
  int i, lst, lpd;
  
  // Get the length of the status string and the pid
  lst = _strlen(st);
  lpd = _strlen(data->pid);
  
  // Iterate through the input string
  for (i = 0; in[i]; i++) {
    if (in[i] == '$') {
      // Handle special variables
      if (in[i + 1] == '?') add_rvar_node(h, 2, st, lst), i++;
      else if (in[i + 1] == '$') add_rvar_node(h, 2, data->pid, lpd), i++;
      else if (in[i + 1] == '\n') add_rvar_node(h, 0, NULL, 0);
      else if (in[i + 1] == '\0') add_rvar_node(h, 0, NULL, 0);
      else if (in[i + 1] == ' ') add_rvar_node(h, 0, NULL, 0);
      else if (in[i + 1] == '\t') add_rvar_node(h, 0, NULL, 0);
      else if (in[i + 1] == ';') add_rvar_node(h, 0, NULL, 0);
      else check_environment_variable(h, in + i, data);
    }
  }
  
  return (i);
}

/**
 * replace_input - Replaces special variables in the input string.
 * @head: The head of the r_var linked list.
 * @input: The input string.
 * @new_input: The new input string.
 * @nlen: The length of the new input string.
 * Return: The new input string.
 */
char *replace_input(r_var **head, char *input, char *new_input, int nlen) {
  r_var *indx;
  int i, j, k;
  
  indx = *head;
  
  // Iterate through the input string
  for (j = i = 0; i < nlen; i++) {
    if (input[j] == '$') {
      // Handle special variables
      if (!(indx->len_var) && !(indx->len_val)) {
        new_input[i] = input[j];
        j++;
      } else if (indx->len_var && !(indx->len_val)) {
        for (k = 0; k < indx->len_var; k++) j++;
        i--;
      } else {
        for (k = 0; k < indx->len_val; k++) {
          new_input[i] = indx->val[k];
          i++;
        }
        j += (indx->len_var);
        i--;
      }
      indx = indx->next;
    } else {
      new_input[i] = input[j];
      j++;
    }
  }
