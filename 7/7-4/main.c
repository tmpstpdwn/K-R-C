/*

Exercise 7-4. Write a private version of scanf analogous to minprintf from the previous
section.

*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int minscanf(char *fmt, ...) {

  int c;
  char *p, *sptr;
  int *iptr;

  va_list ap;
  va_start(ap, fmt);

  char buffer[32];
  int i;

  p = fmt;
  while (*p) {

    if (*p != '%') {

      while (isspace(*p)) p++;
      while (isspace(c =getchar()));

      while (*p != '%' && *p && *p == c && c != EOF) {
        p++;
        c = getchar();
      }

      if (*p != c) {
        return 1;
      } else if (c == EOF) {
        return EOF;
      } else if (*p == '%') {
        ungetc(c, stdin);
      }

      continue;
    }

    for (i = 0; *p && !isalpha(*p); i++, p++) {
      buffer[i] = *p;
    }
    buffer[i++] = *p;
    buffer[i] = '\0';

    switch (*p) {
      case 'd':
        iptr = va_arg(ap, int *);
        scanf(buffer, iptr);
        break;
      case 's':
        sptr = va_arg(ap, char *);
        scanf(buffer, sptr);
        break;
      default:
        fprintf(stderr, "Unsupported format specifier: %c\n", *p);
        return -1;
    }

    p++;
  }

  va_end(ap);

  return 0;
}

int main() {
  int x;
  char str[100];

  printf("Enter int, string: ");
  minscanf("%d-%s", &x, str);

  printf("You entered: %d %s\n", x, str);
  return 0;
}
