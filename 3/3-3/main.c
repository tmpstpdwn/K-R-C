/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRING1 "Following are numbers from 0 to 9: [0-9]\nalphabets from a to z: [a-z]\nalphabets from A to Z: [A-Z]" 
#define STRING2 "-[a-b-c]-[5-1]-[0-9]-"

void expand(char s1[], char s2[]) {
  int i = 0, j = 0;
  int len = strlen(s1);
  while (s1[i] != '\0') {
    if (s1[i] == '-' && i > 0 && i < len-1) {
      char a = s1[i-1], b = s1[i+1];
      if (((islower(a) && islower(b)) || (isupper(a) && isupper(b)) || (isdigit(a) && isdigit(b))) && b > a) {
        for (char k = a+1; k < b; k++, j++)
          s2[j] = k;
      } else {
        s2[j++] = '-';
      }
    } else {
      s2[j++] = s1[i];
    }
    i++;
  }
  s2[j] = '\0';
}

int main() {
  char s1[] = STRING2;
  char s2[1000] = {0};
  expand(s1, s2);
  printf("%s\n", s2);
  return 0;
}
