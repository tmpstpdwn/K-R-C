#include <stdio.h>
#include <string.h>
#include "util.h"
#include <string.h>

static void swap(char x[MAXLINES][MAXLEN], int i, int j) {
    char temp[MAXLEN];
    strcpy(temp, x[i]);
    strcpy(x[i], x[j]);
    strcpy(x[j], temp);
}

static int partition(char x[MAXLINES][MAXLEN], int left, int right) {
  int j, i;
  j = i = left + 1;
  for (; j <= right; j++) {
    if (strcmp(x[j], x[left]) < 0) {
      swap(x, i, j);
      i++;
    }
  }
  swap(x, left, i - 1);
  return i - 1;
}

void quicksort(char x[MAXLINES][MAXLEN], int left, int right) {
  if (left >= right)
    return;
  int pivot = partition(x, left, right);
  quicksort(x, left, pivot - 1);
  quicksort(x, pivot + 1, right);
}
