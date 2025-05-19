/*Exercise 2-10. Rewrite the function lower, upper which converts upper case letters to lower case,
with a conditional expression instead of if-else*/

#include <stdio.h>

char lower(char c) {
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

char upper(char c) {
  return (c >= 'a' && c <= 'z') ? (c - ('a' - 'A')) : c;
}

int main() {
  char c1 = 'A';
  char c2 = 'a';
  char cl = lower(c1);
  char cu = upper(c2);

  printf("lower of %c is %c\n", c1, cl);
  printf("upper of %c is %c\n", c2, cu);

  return 0;
}
