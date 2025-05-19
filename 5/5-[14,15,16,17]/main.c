/*Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.

Exercise 5-17. Add a field-searching capability, so sorting may bee done on fields within
lines, each field sorted according to an independent set of options. (The index for this book
was sorted with -df for the index category and -n for the page numbers.)*/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

char *lineptr[MAX];

int main(int argc, char *argv[]) {
  int nlines;
  int numeric, rev, casenonsense, field, directory;

  numeric = rev = casenonsense = field = directory = 0;

  while (--argc > 0 && **(++argv) == '-') {
    while (*(++*argv)) {
      switch (**argv) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          rev = 1;
          break;
        case 'f':
          casenonsense = 1;
          break;
        case 'k':
          if (argc > 1) {
            field = atoi(*++argv);
            *(*argv + 1) = '\0';
            argc--;
          }
          break;
        case 'd':
          directory = 1;
          break;
        default:
          printf("Error: Unknown option %c!\n", **argv);
          return 1;
      }
    }
  }

  int (*comp)(void *, void *, int) = (int (*)(void *, void *, int))(casenonsense ? strcmplow: strcmpnorm);

  comp = (numeric ? (int (*)(void *, void *, int))(numcmp): comp);

  nlines = readlines(lineptr, MAX);

  if (directory) {
    for (int i = 0; i < nlines; i++) {
      filterlines(lineptr[i]);
    }
  }

  qsortc((void **) lineptr, 0, nlines - 1, comp, field);

  if (rev) {
    reverselines(lineptr, nlines);
  }

  writelines(lineptr, nlines);

  for (int i = 0; i < nlines; i++) {
      free(lineptr[i]);
  }

  return 0;
}
