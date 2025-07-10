/*

Exercise 7-2. Write a program that will print arbitrary input in a sensible way. As a
minimum, it should print non-graphic characters in octal or hexadecimal according to local
custom, and break long text lines.

*/

#include <stdio.h>
#include <ctype.h>

#define WRAP_LEN 100

int main () {
  int c;
  int len = 0;

  while ((c = getchar()) != EOF) {

    if (isprint(c)) {
      printf("%c", c);
      len++;
    } else {
      if (len + 4 > WRAP_LEN) {
        printf("\n");
        len = 0;
      }
      printf("\\%03o", c);
      len += 4;
    }

    if (len == WRAP_LEN) {
      printf("\n");
      len = 0;
    }
    
  }

  printf("\n");

  return 0;
}
