/*Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.*/

#include <stdio.h>
#include <string.h>

int reverse(char s[], int i, int j) {
  if (i >= j)
    return j;

  char t = s[j];
  s[j] = s[i];
  s[i] = t;

  return reverse(s, i+1, j-1);
}

int main() {
  char s[] = "Hello, world!";
  reverse(s, 0, strlen(s)-1);
  printf("%s\n", s);
  return 0;
}
