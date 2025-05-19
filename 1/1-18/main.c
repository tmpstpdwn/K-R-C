/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.*/

#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_BUFFER 100

int getline_n(char line[], int max_buffer) {
  int i, c;
  int last_index = -1;
  int white_space = OUT;

  for (i = 0; (c = getchar()) != EOF && i < max_buffer-1 && c != '\n'; i++) {
    if (c == ' ' || c == '\t') {
      if (white_space == OUT) {
        white_space = IN;
        last_index = i;
      }
    } else {
      white_space = OUT;
      last_index = -1;
    }
    line[i] = c;
  }

  line[i] = '\0';

  if (c == '\n' && i == 0) {
    last_index = 0;
  }

  if (last_index > 0) {
    line[last_index] = '\0';
  }

  return (c == EOF && i == 0) ? -2 : last_index;
}

int main() {
  int last_index;
  char line[MAX_BUFFER] = {0};

  printf("\nREMOVE TRAILING BLANKS\n----------------------\n\n");

  while ((last_index = getline_n(line, MAX_BUFFER)) != -2) {
    if (last_index) {
      printf("%d, %s\n",last_index, line);
    }
  }

  printf("\n");

  return 0;
}
