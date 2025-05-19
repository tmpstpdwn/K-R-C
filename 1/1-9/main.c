/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c;
  int white_space = OUT;

  printf("\nREPLACE WHITESPACE WITH SINGLE BLANK\n------------------------------------\n\n");

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (white_space == OUT) {
        white_space = IN;
        putchar(' ');
      } 
    } else {
      white_space = OUT;
      putchar(c);
    }
  }

  printf("\n");

  return 0;
}
