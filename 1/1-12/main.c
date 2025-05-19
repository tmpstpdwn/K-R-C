//Exercise 1-12. Write a program that prints its input one word per line.

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c;
  int status = OUT;

  printf("\nONE WORD PER LINE\n-----------------\n\n");

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      status = OUT;
    } else {
      if (status == OUT) {
        putchar('\n');
        status = IN;
      }
      putchar(c);
    }
  }

  printf("\n");

  return 0;
}
