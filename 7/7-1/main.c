/*

Exercise 7-1. Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0]

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  int to_lower = 0;
  int to_upper = 0;

  if (strstr(argv[0], "upper")) {
    to_upper = 1;
  } else if (strstr(argv[0], "lower")) {
    to_lower = 1;
  } else {
    fprintf(stderr, "Error: name the program with \'lower\' or \'upper\' in the name!\n");
    return 1;
  }

  int c;
  while ((c = getchar()) != EOF) {
    if (to_upper) {
      putchar(toupper(c));
    } else {
      putchar(tolower(c));
    }
  }
  return 0;
}
