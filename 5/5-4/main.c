/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.*/

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
  int len_s = strlen(s), len_t = strlen(t);
  if (len_t > len_s)
    return 0;
  s += len_s - len_t;
  for(; *s == *t; s++, t++)
    if (*t == '\0')
      return 1;
  return 0;
}

int main() {
  char s[] = "Hello world!";
  char t[] = "!";
  printf("%d\n", strend(s, t));
  return 0;
}
