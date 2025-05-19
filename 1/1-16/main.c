/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.*/

#include <stdio.h>

#define MAXLEN 100

int getline_n(char line[], int maxlen) {
  int i, c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < maxlen-1) {
      line[i] = c;
    }
  }

  if (i < maxlen - 1) {
      line[i] = '\0';
  } else {
      line[maxlen - 1] = '\0';
  }

  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}

int main() {
  char line[MAXLEN];
  char longest[MAXLEN];

  int max = 0;
  int len = 0;

  printf("\nLONGEST LINE\n------------\n");

  while ((len = getline_n(line, MAXLEN)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  printf("\n[%d]: %s%s\n\n", max, longest, (max >= MAXLEN) ? "...": "");

  return 0;
}
