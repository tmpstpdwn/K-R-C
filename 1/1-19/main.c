//Exercise 1-19. Write a function reverse(s) that reverses the character string s.

#include <stdio.h>
#include <string.h>

#define STRING "Hello, World!"

void reverse(char s[]) {
  int i, j, c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main() {
  char s[] = STRING;
  reverse(s);
  printf("Result = %s\n", s);
  return 0;
}
