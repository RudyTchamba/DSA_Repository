void reverse(char* str){
  int left = 0;
  int right = strlen(str) - 1;

  while(left < right){
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
    left++;
    right--;
  }
}


int main() {
  char str[] = "abcd";
    printf("Original string: %s\n", str);

    reverse(str);

    printf("Reversed string: %s\n", str);
  return 0;
}