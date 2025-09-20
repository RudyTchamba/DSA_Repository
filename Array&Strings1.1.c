#include <stdbool.h>
#include <string.h>

//Using Brute Force

bool isUniqueChars1(const char* str){
  int length = strlen(str);

  for(int i = 0; i < length; i++){
    for(int j = i+1; j< length; j++){
      if(str[i] == str[j]){
        return false;  // A Duplicate caracter is found
      }
    }
  }
  return true;  // A Duplicate caracter is not found
}

//Using hashtables

bool isUniqueChars2(const char* str){
  bool seen[26] = {false};

  for(int i = 0; str[i] != '\0'; i++){
    char current_char = str[i];

    // Check if the character is a lowercase letter
    if (current_char < 'a' || current_char > 'z') {
      return false;
    }

    int index = current_char - 'a';
    if(seen[index]){
      return false;
    }
    seen[index] = true;
  }
  return true;
}

int main() {
  printf("%d\n", isUniqueChars1("Tchambt"));
  return 0;
}