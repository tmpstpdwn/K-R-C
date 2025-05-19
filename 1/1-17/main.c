//Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>

#define MAXLEN 1000

int getline_n(char line[], int maxlen) {
  int i, c;

  for (i = 0; i < maxlen-1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    i++;
  }
  line[i] = '\0';
  return i;
}

int main() {
  char line[MAXLEN];

  int max = 80;
  int len = 0;

  printf("\nLONGER THAN 80\n--------------\n");

  while ((len = getline_n(line, MAXLEN)) > 0) {
    if (len > max) {
      printf("%s", line);
    }
  }

  printf("\n");

  return 0;
}
