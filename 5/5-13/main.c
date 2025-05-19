/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

#define N 10
#define MAXLINE 1000

int getline_n(char s[], int lim) {
  int i, c;

  for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
    s[i] = c;

  if (c == EOF && i == 0)
    return -1;

  s[i] = '\0';
  return i;
}

int main(int argc, char *argv[]) {
  int n = N;

  if (argc >= 2 && **++argv == '-') {
    ++*argv;
    if (isnum(*argv)) {
      n = atoi(*argv);
    }
  }

  char **p = calloc(n, sizeof(char *));

  if (p == NULL) {
    printf("Error: MeM Issue!\n");
    return 1;
  }

  int i;
  char buffer[MAXLINE];
  int len;
  int lineno = 0;
  int currenti = 0;

  while ((len = getline_n(buffer, MAXLINE)) >= 0) {
    if (p[currenti] != NULL) {
      free(p[currenti]);
    }

    char *line = malloc(len + 1);
    if (line == NULL) {
      printf("Error: MeM Issue!\n");
      return 1;
    }

    strcpy(line, buffer);

    p[currenti] = line;

    currenti = (currenti + 1) % n;
    lineno++;
  }

  if (p[currenti] == NULL) {
    currenti = 0;
  }

  int width = 1;
  int temp = lineno;
  while (temp > 0) {
    temp /= 10;
    width++;
  }

  printf("\n");

  for (int j = (lineno >= n)? n: lineno; --j >= 0; currenti = (currenti + 1) % n) {
    if (p[currenti] == NULL) {
      continue;
    }
    printf("%*d | %s\n", width, lineno - j, p[currenti]);
    free(p[currenti]);
  }

  free(p);

  printf("\n");

  return 0;
}
