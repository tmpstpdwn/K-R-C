/*Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.*/

#include <stdio.h>

int bitcount(unsigned int x) {
  int i = 0;
  while (x) {
    x &= (x - 1);
    i++;
  }
  return i;
}

int main() {
  unsigned int bin = 0b110111011011;
  int bitcount1 = bitcount(bin);
  printf("Bit count of 1 in %d is: %d\n", bin, bitcount1);
  return 0;
}
