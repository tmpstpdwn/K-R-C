/*Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/

#include <stdio.h>

int TOTALBITS = sizeof(int) * 8;

int rightrot(int x, int n) {
  int rightmost_bits = x & ~(~0 << n);
  x = x >> n;
  rightmost_bits = rightmost_bits << (TOTALBITS - n);
  x = x | rightmost_bits;
  return x;
}

int main() {
  int x = rightrot(213, 3);
  printf("%d\n", x);
  return 0;
}
