//Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>
#include <unistd.h>  // For isatty()

#define IN 1
#define OUT 0

int main(int argc, char *argv[]) {
  int c, nc, tc, bc, cc, wc;
  nc = tc = bc = cc = wc = 0;

  int wcs = OUT;

  int from_file = 0;

  FILE *fp = NULL;

  if (argc > 1) {
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("\nError opening file\n\n");
      return 1;
    }
    from_file = 1;
    printf("\nTextAnalyzer [%s]\n------------\n", argv[1]);
  } else {
    fp = stdin;
    if (isatty(fileno(stdin))) {
      printf("\nTextAnalyzer [Write something, Enter, Ctrl-D/Z to see results]\n------------\n\n");
    } else {
      printf("\nTextAnalyzer [STDIN]\n------------\n");
    }
  }

  while ((c = fgetc(fp)) != EOF) {

    if (c == '\n') {
      wcs = OUT;
      nc++;
    } else if (c == '\t') {
      wcs = OUT;
      tc++;
    } else if (c == ' ') {
      wcs = OUT;
      bc++;
    } else {
      if (wcs == OUT) {
        wcs = IN;
        wc++;
      }
      cc++;
    }
  }

  if (nc == 0 && cc == 0 && wc == 0) {
    printf("\n[%s] is empty or contains no readable characters.\n\n", from_file ? argv[1] : "STDIN");
    return 0;
  }

  printf("\n[ %d Line/s, %d tab/s, %d space/s, %d character/s, %d word/s ]\n\n", nc, tc, bc, cc, wc);

  if (from_file) {
    fclose(fp);
  }

  return 0;

}
