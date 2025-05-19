/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.*/

#include <stdio.h>
#define LEN 100

char buff[LEN];
int bufp = 0;

char getch(void) {
    return (bufp > 0)? buff[--bufp]: getchar();
}

void ungetch(char c) {
    if (bufp < LEN) {
        buff[bufp++] = c;
    }
}

int main() {
    int c, comment = 0, string = 0;

    while ((c = getch()) != EOF) {

        if (c == '"') {
            string = (string == 0)? 1: 0;
        }

        if (c == '/' && !string) {
            int t = getch();
            if (t == '/' && !comment) {
                while ((c = getch()) != '\n' && c != EOF);
            } else if (t == '*') {
                comment = 1;
            } else if (t != EOF) {
                ungetch(t);
            }
        }

        if (c == '*' && !string) {
            int t = getch();
            if (t == '/') {
                comment = 0;
                continue;
            } else if (t != EOF) {
                ungetch(t);
            }
        }

        if (!comment && c != EOF) {
                putchar(c);
        }
    }

    return 0;
}
