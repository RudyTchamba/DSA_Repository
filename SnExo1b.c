#include <stdio.h>

int position(char letter) {
   return letter - 'A' + 1;
}
void countFrequency(char input[], int frequency[]) {
    int i, pos;
    for (i = 0; input[i] != '\0'; i++) {
        pos = position(input[i]);
        frequency[pos - 1]++;
    }
}
int main() {
    char input[] = "HELLO";
    int frequency[26] = {0};
    int i;
    countFrequency(input, frequency);
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, frequency[i]);
    }
return 0;
}
