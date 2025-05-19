/*Exercise 5-12. Extend entab and detab to accept the shorthand
entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char *argv[]) {
  int c, i, spaces, m, n, col;
  col = m = 0;
  n = TABSTOP;

  while (--argc > 0) {
    ++argv;
    if (**argv == '-' && isnum(++*argv)) {
      m = atoi(*argv);
    } else if (**argv == '+' && isnum(++*argv)) {
      n = atoi(*argv);
    } else {
      printf("Usage: detab -m +n\n");
      return 1;
    }
  }

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      if (col >= m)
        spaces = n - (col % n);
      else
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
