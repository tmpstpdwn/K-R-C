/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/

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

void itoa(int n, char s[], int b) {
  int i = 0, sign, temp;
  unsigned int num;

  if ( n < 0) {
    num = (unsigned)-n;
  } else {
    num = n;
  }

  do {
    temp = num % b;
    if (temp >= 10) {
      s[i++] = 'A' + (temp - 10);
    } else {
      s[i++] = '0' + temp;
    }
  } while ((num /= b) > 0);

  if (n < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

int main() {
  char s[12] = {0};
  itoa(-26, s, 16);
  printf("%s\n", s);
  return 0;
}
