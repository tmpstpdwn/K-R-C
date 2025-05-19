/*Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.*/

#include <stdio.h>

#define HEX "0xABCD"

int htoi(char hex_inp[]) {
  int value = 0;
  int temp = 0;

  for (int i = 0; hex_inp[i] != '\0'; i++) {
    if (i == 0 && hex_inp[i] == '0' && (hex_inp[i+1] == 'x' || hex_inp[i+1] == 'X')) {
      i = 2;
    }
    if (hex_inp[i] >= '0' && hex_inp[i] <= '9') {
      temp =  hex_inp[i] - '0';
    } else if (hex_inp[i] >= 'a' && hex_inp[i] <= 'f') {
      temp = ( hex_inp[i] - 'a') + 10;
    } else if (hex_inp[i] >= 'A' && hex_inp[i] <= 'F') {
      temp = ( hex_inp[i] - 'A') + 10;
    }
    value = value * 16 + temp;
  }

  return value;
}

int main() {
  char hex[] = HEX;
  int hex_val = htoi(hex);
  printf("Hex %s is %d in Decimal.\n", hex, hex_val);
  return 0;
}
