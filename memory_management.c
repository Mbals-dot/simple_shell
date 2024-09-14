#include "shell.h"

/**
 * copy_memory - Copies memory from one location to another.
 * @destination: The destination memory location.
 * @source: The source memory location.
 * @size: The number of bytes to copy.
 */
void copy_memory(void *destination, const void *source, unsigned int size) {
  char *char_source = (char *)source;
  char *char_destination = (char *)destination;
  unsigned int i;

  // Copy memory byte by byte
  for (i = 0; i < size; i++) {
    char_destination[i] = char_source[i];
  }
}

/**
 * reallocate_memory - Reallocates memory to a new size.
 * @ptr: The pointer to the memory block to reallocate.
 * @old_size: The old size of the memory block.
 * @new_size: The new size of the memory block.
 * Return: The reallocated memory block.
 */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size) {
  void *new_ptr;

  // If the pointer is NULL, allocate new memory
  if (ptr == NULL) {
    return (malloc(new_size));
  }

  // If the new size is 0, free the memory and return NULL
  if (new_size == 0) {
    free(ptr);
    return (NULL);
  }

  // If the new size is the same as the old size, return the original pointer
  if (new_size == old_size) {
    return (ptr);
  }

  // Allocate new memory
  new_ptr = malloc(new_size);

  // Check if memory allocation failed
  if (new_ptr == NULL) {
    return (NULL);
  }

  // Copy the memory from the old block to the new block
  if (new_size < old_size) {
    copy_memory(new_ptr, ptr, new_size);
  } else {
    copy_memory(new_ptr, ptr, old_size);
  }

  // Free the old memory block
  free(ptr);

  return (new_ptr);
}

/**
 * reallocate_double_pointer - Reallocates a double pointer to a new size.
 * @ptr: The double pointer to reallocate.
 * @old_size: The old size of the double pointer.
 * @new_size: The new size of the double pointer.
 * Return: The reallocated double pointer.
 */
char **reallocate_double_pointer(char **ptr, unsigned int old_size, unsigned int new_size) {
  char **new_ptr;
  unsigned int i;

  // If the pointer is NULL, allocate new memory
  if (ptr == NULL) {
    return (malloc(sizeof(char *) * new_size));
  }

  // If the new size is the same as the old size, return the original pointer
  if (new_size == old_size) {
    return (ptr);
  }

  // Allocate new memory
  new_ptr = malloc(sizeof(char *) * new_size);

  // Check if memory allocation failed
  if (new_ptr == NULL) {
    return (NULL);
  }

  // Copy the pointers from the old block to the new block
  for (i = 0; i < old_size; i++) {
    new_ptr[i] = ptr[i];
  }

  // Free the old memory block
  free(ptr);

  return (new_ptr);
}
