/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.*/

#include <stdio.h>

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[j] != '\0') {
    switch (t[j]) {
      case '\n': {
        s[i++] = '\\';
        s[i] = 'n';
        break;
      }
      case '\t': {
        s[i++] = '\\';
        s[i] = 't';
        break;
      }
      default: {
        s[i] = t[j];
      }
    }
    j++;
    i++;
  }
  s[i] = '\0';
}

void escapeb(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[i+1] != '\0') {
    if (t[i] == '\\' && t[i+1] == 'n') {
      s[j] = '\n';
      i++;
    } else if (t[i] == '\\' && t[i+1] == 't') {
      s[j] = '\t';
      i++;
    } else {
      s[j] = t[i];
    }
    i++;
    j++;
  }
  s[j++] = t[i];
  s[j] = '\0';
}

int main() {
  char t[] = "hello\nbye\thi\nhello.";
  char s[100] = {0};
  char b[100] = {0};
  escape(s, t);
  printf("%s\n", s);
  escapeb(b, s);
  printf("%s\n", b);
  return 0;
}
