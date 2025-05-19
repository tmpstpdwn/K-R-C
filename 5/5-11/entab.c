/*Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char *argv[]) {
  int c, blanks, nstop, cols;
  cols = 0;
  int tabstops[STOPS] = {0};
  int current_stop = 0;
  int args;

  while (--argc > 0) {
    ++argv;
    if (isnum(*argv) && current_stop < STOPS)
      tabstops[current_stop++] = atoi(*argv);
  }
  args = (current_stop)? 1: 0;
  current_stop = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      blanks++;
    else {
      while (blanks > 0) {
        if (args) {
          if (!tabstops[current_stop])
            current_stop = 0;
          nstop = tabstops[current_stop] - (cols % tabstops[current_stop]);
          current_stop++;
        } else {
          nstop = TABSTOP - (cols % TABSTOP);
        }
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
