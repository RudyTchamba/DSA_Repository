int removeDuplicates(char* str) {
  int write = 0;
  for (int read = 0; str[read]; read++) {
    int duplicate = 0;
    for (int i = 0; i < read; i++) {
      if (str[i] == str[read]) {
        duplicate = 1;
        break;
      }
    }
    if (!duplicate) {
      str[write++] = str[read];
    }
  }
  str[write] = '\0';
  return write;
}

int main() {
  char str[] = "aabbccdd";
  printf("Original string: %s\n", str);

  int newLength = removeDuplicates(str);
  printf("New string: %.*s\n", newLength, str);

  return 0;
}