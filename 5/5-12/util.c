#include <ctype.h>

int isnum(char *s) {
  while (*s) {
    if (!isdigit(*s))
      return 0;
    s++;
  }
  return 1;
}
