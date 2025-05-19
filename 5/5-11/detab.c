/*Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char *argv[]) {
  int c, i, spaces, col = 0;
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
    if (c == '\t') {
      if (args) {
        if (!tabstops[current_stop])
          current_stop = 0;
        spaces = tabstops[current_stop] - (col % tabstops[current_stop]);
        current_stop++;
      } else {
        spaces = TABSTOP - (col % TABSTOP);
      }
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
