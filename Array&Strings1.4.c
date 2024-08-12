#include <ctype.h>

// To execute C, please define "int main()"
int areAnagrams(char* s1, char* s2){
  if(strlen(s1) != strlen(s2)){
    return 0;
  }

  int count[26]={0};

  for(int i = 0; s1[i]; i++){
    count[tolower(s1[i]) - 'a']++;
  }

  for(int i = 0; s2[i]; i++){
    count[tolower(s2[i]) - 'a']--;
  }

  for(int i = 0; i < 26; i++){
    if(count[i]!= 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  char* s1 ="listen";
  char* s2 ="silent";
  
  printf("'%s' and '%s' are the anagrams: %d\n", s1, s2, areAnagrams(s1, s2));

  return 0;
}