/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.*/

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

void itoa(int n, char s[]) {
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
  s[i] = '\0';
  reverse(s);
}

int main() {
  int n = -2147483648;
  char s[12] = {0};
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}
