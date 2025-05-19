/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?*/

#include <stdio.h>

#define TABSTOP 4

int main() {
  int c, blanks, nstop, cols;
  cols = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      blanks++;
    else {
      while (blanks > 0) {
        nstop = TABSTOP - (cols % TABSTOP);
        if (blanks >= nstop && nstop != 0) {
          putchar('\t');
          cols += nstop;
          blanks -= nstop;
        } else {
          putchar(' ');
          cols++;
          blanks--;
        }
      }

      putchar(c);
      cols++;

      if (c == '\n') {
        cols = 0;
      }
    }
  }

  return 0;
}
