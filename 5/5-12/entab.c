/*Exercise 5-12. Extend entab and detab to accept the shorthand
entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char *argv[]) {
  int c, blanks, nstop, cols, m, n;
  cols = m = 0;
  n = TABSTOP;

  while (--argc > 0) {
    ++argv;
    if (**argv == '-' && isnum(++*argv)) {
      m = atoi(*argv);
    } else if (**argv == '+' && isnum(++*argv)) {
      n = atoi(*argv);
    } else {
      printf("Usage: entab -m +n\n");
      return 1;
    }
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      blanks++;
    else {
      while (blanks > 0) {
        if (cols >= m)
          nstop = n - (cols % n);
        else
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
