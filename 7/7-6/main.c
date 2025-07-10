/*

Exercise 7-6. Write a program to compare two files, printing the first line where they differ.

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *f1, *f2;

  if (--argc != 2) {
    fprintf(stderr, "Error: excess / not sufficient arguments!\n");
    return 1;
  }

  f1 = fopen(argv[1], "r");
  f2 = fopen(argv[2], "r");
  if (f1 == NULL || f2 == NULL) {
      fprintf(stderr, "Error: file error!\n");
      return 1;
  }

  char line1[100];
  char line2[100];

  int lineno = 0;

  char *l = fgets(line1, sizeof(line1), f1);
  char *r = fgets(line2, sizeof(line2), f2);

  while (l && r) {
    lineno++;
    if (strcmp(line1, line2) != 0) {
        printf("line no: %d\n", lineno);
        printf("%s: %s", argv[1], line1);
        printf("%s: %s", argv[2], line2);
        break;
    }
    l = fgets(line1, sizeof(line1), f1);
    r = fgets(line2, sizeof(line2), f2);
  }

  if (!l && !r) {
      printf("Both files are identical.\n");
  } else if (!l || !r) {
      printf("line no: %d\n", ++lineno);
      if (!l)
          printf("%s: <EOF>\n", argv[1]);
      else
          printf("%s: %s", argv[1], line1);
      if (!r)
          printf("%s: <EOF>\n", argv[2]);
      else
          printf("%s: %s", argv[2], line2);
  }

  fclose(f1);
  fclose(f2);
  return 0;
}
