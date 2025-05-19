/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/

#include <stdio.h>
#include <ctype.h>

#define LEN 100

char buf[LEN];
int bufp = 0;

int getch(void) {
  return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c) {
  if (bufp < LEN)
    buf[bufp++] = c;
  else 
    printf("buf full!\n");
}

int getint(int* x) {
  int c, sign;
  while (isspace(c = getch()));
  if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-')? -1: 1;
  if (c == '-' || c == '+') {
    int t = getch();
    if (!isdigit(t)) {
      ungetch(t);
      ungetch(c);
      return 0;
    }
    c = t;
  }
  for(*x = 0; isdigit(c); c=getch())
    *x = *x * 10 + (c - '0');
  *x *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  int x;
  getint(&x);
  printf("%d\n", x);
  return 0;
}
