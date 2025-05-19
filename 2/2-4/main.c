//Exercise 2-4. Write squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze(char s1[], char s2[]) {
  int i, j;
  i = j = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i]) {
      s1[j] = s1[i];
      j++;
    }
    i++;
  }
  s1[j] = '\0';
}

int main() {
  char s1[] = "Hello, how are you.";
  char s2[] = "Hello, Brother dude";
  squeeze(s1, s2);
  printf("After sqeezing: %s\n", s1);
  return 0;
}
