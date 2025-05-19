//Exercise 3-1. binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]

#include <stdio.h>

int binsearch(int x, int v[], int n) {
  int low, mid, high;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid]) {
      high = mid + 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  int sorted_array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
  int x = 1;
  int n = 10;
  int i = binsearch(x, sorted_array, n);
  printf("Index of %d is %d\n", x, i);
  return 0;
}
