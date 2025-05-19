/* Exercise 2-5.
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
*/

#include <stdio.h>

int any(char s1[], char s2[]) {
  int n = -1;
  for (int i = 0; s1[i] != '\0' && n == -1; i++) {
    for (int j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        n = i;
        break;
      }
    } 
  }
  return n;
}

int main() {
  char s1[] = "Hello";
  char s2[] = "llo";
  int n = any(s1, s2);
  printf("any: %d\n", n);
  return 0;
}
