/*Exercise 1-2. Experiment to find out what happens when prints's argument string contains
\c, where c is some character not listed above.*/

#include <stdio.h>

/*
main.c: In function ‘main’:
main.c:4:16: warning: unknown escape sequence: '\l'
    4 |   printf("\l\n");
      |                ^
*/

int main() {
  printf("\l\n");
  return 0;
}
