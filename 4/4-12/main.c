/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.*/

#include <stdio.h>

int itoar(int x, char s[], int i) {
  if (x < 0) {
    x = (unsigned int)x; 
    s[i] = '-';
    x = -x;
    i++;
  }

  if (x / 10) {
    i = itoar(x / 10, s, i) + 1;
  }

  s[i] = '0' + x % 10;
  s[i+1] = '\0';
  return i;
}

int main() {
  char s[12];
  itoar(-1242136, s, 0);
  printf("%s\n", s);
  return 0;
}
