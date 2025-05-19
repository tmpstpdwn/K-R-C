//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.

#include <stdio.h>

int main() {
  int c;
  int tc = 0;
  int nchr[95];

  for (int i = 0; i < 95; i++) {
    nchr[i] = 0;
  }

  printf("\nASCII FREQUENCY HISTOGRAM\n-------------------------\n");

  while ((c = getchar()) != EOF) {
    if (c > 32 && c < 127) {
      nchr[c-32]++;
    }
  }

  printf("\n");

  for (int i = 0; i < 95; i++) {
    if (nchr[i] != 0) {
      printf("%c: ", i + 32);
      for (int j = 0; j < nchr[i]; j++) {
        printf("-");
      }
      printf(" [ %d ]\n", nchr[i]);
      tc++;
    }
  }

  printf("\nTotal characters used: %d\n", tc);

  printf("\n");

  return 0;
}
