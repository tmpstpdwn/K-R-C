/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include <stdio.h>

int invert(int x, int p, int n) {
  x ^= (~(~0 << n)) << (p+1-n);
  return x;
}

int main() {
  int x = invert(204, 4, 3);
  printf("%d\n", x);
  return 0;
}
