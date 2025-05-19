#include <stdio.h>
#include <ctype.h>
#include "rpc.h"

// Line buffer for input.
static char line[LEN];
static int pos = 0;

char getop(char s[]) {
  int i = 0, c;

  // If the buffer is empty or exhausted, read a new line
  if (line[pos] == '\0') {
      if (fgets(line, LEN, stdin) == NULL) {
          return EOF;
      }
      pos = 0;
  }

  // Avoid whitespace.
  while ((s[0] = c = line[pos++]) == ' ' || c == '\t');
  s[1] = '\0';

  // Check for command syntax and buffer them.
  if (isupper(c)) {
    int t = line[pos++];
    if (islower(t)) {
      s[1] = t;
      s[2] = '\0';
      return c;
    }
    pos--;
  }

  // Look for sign characters.
  if (c == '-' || c == '+') {
    int t = line[pos++];
    if (isdigit(t) || t == '.') {
      s[i = 1] = c = t;
    } else {
      pos--;
      return c;
    }
  }

  // Return if a character is found.
  if (!isdigit(c) && c != '.') {
    return c;
  }

  // Get a number.
  if (isdigit(c))
    while (isdigit(s[++i] = c = line[pos++]));
  if (c == '.')
    while (isdigit(s[++i] = c = line[pos++]));
  s[i] = '\0';

  pos--;

  return NUMBER;
}
