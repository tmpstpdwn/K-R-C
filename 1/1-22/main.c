/*Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/

#include <stdio.h>

#define N 50
#define TABSTOP 8

int main() {
  int c;
  int cols = 0;
  int len = 0;
  char word[N + 1];
  int i = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      if (i < N)
        word[i++] = c;
      len++;
    } else {
      if (len > 0) {
        if (cols + len > N) {
          putchar('\n');
          cols = 0;
        }
        for (int j = 0; j < i; j++)
          putchar(word[j]);
        cols += len;
        i = len = 0;

        if (c == ' ') {
          if (cols + 1 > N) {
            putchar('\n');
            cols = 0;
          } else {
            putchar(' ');
            cols += 1;
          }
        } else if (c == '\t') {
          int spaces = TABSTOP - (cols % TABSTOP);
          if (cols + spaces > N) {
            putchar('\n');
            cols = 0;
          } else {
            for (int s = 0; s < spaces; s++) putchar(' ');
            cols += spaces;
          }
        } else if (c == '\n') {
          putchar('\n');
          cols = 0;
        }
      }
    }
  }

  if (len > 0) {
      if (cols + len > N)
          putchar('\n');
      for (int j = 0; j < i; j++)
          putchar(word[j]);
  }

  return 0;
}
