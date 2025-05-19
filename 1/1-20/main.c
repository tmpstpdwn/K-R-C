/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?*/

#include <stdio.h>

#define TABSTOP 4

int main() {
  int c, i, spaces, col = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      spaces = TABSTOP - (col % TABSTOP);
      i = 0;
      while (i < spaces) {
        putchar(' ');
        i++;
        col++;
      }
    } else {
      putchar(c);
      col++;
      if (c == '\n') {
        col = 0;
      }
    } 
  }
  return 0;
}
