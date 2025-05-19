/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.*/

#include <stdio.h>

void strcat_n(char *s, char *t) {
  for (; *s != '\0'; s++);
  for (; (*s = *t) != '\0'; s++, t++);
  *s = '\0';
}

int main() {
  char s[] = "Hello world.";
  char t[] = "How are you my mahnn!";
  strcat_n(s, t);
  printf("%s\n", s);
  return 0;
}
