/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/

#include <stdio.h>

#define LONGEST 50

int main() {
  int c;
  int word_sizes[LONGEST];
  int word_len = 0;
  int total_result = 0;

  for (int i = 0; i < LONGEST; i++) { 
    word_sizes[i] = 0; 
  }

  printf("\nWORD LENGTH HISTOGRAM\n---------------------\n");

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' | c == '\t') {
      if (word_len > 0 && word_len < LONGEST) {
        word_sizes[word_len]++;
        word_len = 0;
      }
    } else {
      word_len++;
    } 
  }

  printf("\n");

  for (int i = 0; i < LONGEST; i++) {
    if (word_sizes[i] != 0) {
      printf("%d: ", i);
      for (int j = 0; j < word_sizes[i]; j++) {
        printf("-");
      }
      printf(" [ %d ]\n", word_sizes[i]);
      total_result++;
    }
  }

  printf("\n");

  printf("Total results: %d\n", total_result);

  printf("\n");

  return 0;
}
