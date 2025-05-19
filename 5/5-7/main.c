/*Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

char *lineptr[MAXLINES];

int getline_n(char s[], int lim) {
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int readlines(char lines[MAXLINES][MAXLEN], int maxlines) {
  int len, nlines;
  char line[MAXLEN];
  nlines = 0;
  while ((len = getline_n(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(lines[nlines++], line);
    }
  return nlines;
}

void writelines(char lines[MAXLINES][MAXLEN], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lines[i]);
}

int main() {
  char lines[MAXLINES][MAXLEN];
  int nlines = readlines(lines, MAXLINES);
  quicksort(lines, 0, nlines-1);
  writelines(lines, nlines);
  return 0;
}
