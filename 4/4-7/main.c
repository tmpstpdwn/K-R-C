/*Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?*/

#include <stdio.h>

char buf[LEN];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < LEN)
        buf[bufp++] = c;
    else
        printf("Error [ungetch]: too many characters\n");
}

void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);
    }
}
