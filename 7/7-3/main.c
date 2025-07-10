/*

Exercise 7-3. Revise minprintf to handle more of the other facilities of printf.

*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

void minprintf(char *fmt, ...) {

  char *p, *sval;
  int ival;
  double dval;

  va_list ap;
  va_start(ap, fmt);

  char buffer[10];
  int i;

  for (p = fmt; *p; p++) {

    if (*p != '%') {
      putchar(*p);
      continue;
    }

    for (i = 0; *p && !isalpha(*p); i++, p++) {
      buffer[i] = *p;
    }
    buffer[i++] = *p;
    buffer[i] = '\0';

    switch (*p) {
      case 'd':
        ival = va_arg(ap, int);
        printf(buffer, ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf(buffer, dval);
        break;
      case 's':
        sval = va_arg(ap, char *);
        printf(buffer, sval);
        break;
      default:
        printf("%s", buffer);
        break;
    }
  }
  va_end(ap);
}

int main() {
  minprintf("Name: %-10s | Age: %04d | GPA: %.2f%%\n", "Alex", 7, 3.75);
  return 0;
}
