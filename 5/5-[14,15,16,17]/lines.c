// INCLUDES.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

// Read a single line / until EOF / until buffer full, return recorded line length.
static int readline(char s[], int max) {
  int i, c;

  for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  s[i] = '\0';
  return i;
}

// Read lines until EOF / until buffer full, return recorded line count.
int readlines(char **s, int nlines) {
  int len, i;
  char line[MAX];

  i = 0;

  while((len = readline(line, MAX)) > 0 && i < nlines-1) {
    char *p = malloc(len + 1);
    if (p == NULL)
      return -1;
    strcpy(p, line);
    *s = p;
    s++, i++;
  }

  return i;
}

// Write lines onto stdout from buffer.
void writelines(char **s, int nlines) {
  while (nlines > 0) {
    printf("%s\n", *s);
    nlines--, s++;
  }
}

// Reverse order of lines in buffer.
void reverselines(char **s, int nlines) {
  char **start = s;
  char **end, *temp;

  end = s + nlines - 1;

  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}

// Return pointer to nth field or NULL.
const char *fieldpointer(const char *s, int n) {
  int in = 0, word = 0;

  while (*s != '\0') {
    if (*s == ' ' || *s == '\t' || *s == '\n') {
      in = 0;
    } else {
      if (in == 0) {
        in = 1;
        word++;
      }
    }
    if (word == n) {
      return s;
    }
    s++;
  }

  return NULL;
}

// Return length of a field.
int fieldlen(const char *s) {
  int len;
  for (len = 0; *s != '\0' && *s != ' ' && *s != '\t' && *s != '\n'; s++, len++);
  return len;
}

// Filter lines of non dictionary characters.
void filterlines(char *line) {
  char *dst = line;

  while (*line) {
    if (isalnum((unsigned char)*line) || *line == ' ') {
      *dst++ = *line;
    }
    line++;
  }

  *dst = '\0';
}
