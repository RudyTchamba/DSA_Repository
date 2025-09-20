#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_spaces(char *str) {
  int spaces = 0;
  int i, j;

  // Count the number of spaces
  for (i = 0; str[i]; i++) {
    if (str[i] == ' ') {
      spaces++;
    }
  }

  // Calculate the new length of the string
  int new_length = i + spaces * 2;

  // Create a new string with enough space for the replacements
  char *new_str = (char *) malloc(new_length + 1);

  // Replace the spaces with '%20'
  for (i = 0, j = 0; str[i]; i++) {
    if (str[i] == ' ') {
      new_str[j++] = '%';
      new_str[j++] = '2';
      new_str[j++] = '0';
    } else {
      new_str[j++] = str[i];
    }
  }

  new_str[j] = '\0'; // Null-terminate the new string

  // Copy the new string back to the original string
  strcpy(str, new_str);

  // Free the dynamically allocated memory
  free(new_str);
}

int main() {
  char str[] = "Hello World";
  printf("Original string: %s\n", str);

  replace_spaces(str);
  printf("New string: %s\n", str);

  return 0;
}