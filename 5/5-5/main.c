/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.*/

#include <stdio.h>
#include <string.h>

void strncat_n(char *s, char *t, int n) {
  char *stop = (n < strlen(t))? t + n: t + strlen(t);
  for (; *s != '\0'; s++);
  for (; (*s = *t) && t < stop; s++, t++);
  *s = '\0';
}

int strncmp_n(char *s, char *t, int n) {
  char *stop = (n < strlen(t))? t + n: t + strlen(t);
  for (; (*s == *t) && t < stop && *s; s++, t++);
  return (*s == *t || !(*s))? 0: 1;
}

void strncpy_n(char *s, char *t, int n) {
  char *stop = (n < strlen(t))? t + n: t + strlen(t);
  for (; (*s = *t) && t < stop; s++, t++);
  *++s = '\0';
}
