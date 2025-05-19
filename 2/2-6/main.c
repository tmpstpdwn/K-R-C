/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.*/

#include <stdio.h>

int setbits(int x, int p, int n, int y) {

  x = x & ~(~(~0 << n) << (p+1-n));
  y = (y & ~(~0 << n)) << (p+1-n);
  x = x | y;

  return x;
}

int main() {
  int x = setbits(170, 4, 3, 204);
  printf("%d\n", x);
  return 0;
}
