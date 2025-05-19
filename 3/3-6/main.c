/*Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
  int i, j, c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int w) {
  int i = 0, sign;
  unsigned int num;

  if ( n < 0) {
    num = (unsigned)-n;
  } else {
    num = n;
  }

  do {
    s[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);

  if (n < 0) {
    s[i++] = '-';
  }

  if (i < w) {
    for (int j = 0; j < (w - i) ; i++) {
      s[i] = ' ';
    }
  }

  s[i] = '\0';
  reverse(s);
}

int main() {
  int n = -1234;
  char s[12] = {0};
  itoa(n, s, 6);
  printf("%s\n", s);
  return 0;
}
