/*Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
getfloat return as its function value?*/

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

int getfloat(float *x) {
  int c, sign, p;
  while (isspace(c = getch()));
  if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-')? -1: 1;
  if (c == '-' || c == '+')
    c = getch();
  for(*x = 0; isdigit(c); c=getch())
    *x = *x * 10 + (c - '0');
  if (c == '.')
    c = getch();
  for(p = 1; isdigit(c); c=getch()) {
    *x = *x * 10 + (c - '0');
    p *= 10;
  }
  *x = sign * (*x/p);
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  float x;
  getfloat(&x);
  printf("%f\n", x);
  return 0;
}
