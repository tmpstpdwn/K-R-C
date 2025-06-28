/*

Exercise 6-1. Our version of getword does not properly handle underscores, string constants,
comments, or preprocessor control lines. Write a better version.

*/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

enum TokenType {
    NONE,
    COMMENT,
    QOUTES,
    PD,
    WORD
};

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

enum TokenType getword(char *word, int lim) {
    int c, next;
    *word = '\0';

    while (isspace(c = getch()))
        ;

    if (c == EOF) {
        return EOF;
    }

    if (c == '/') {
        if ((next = getch()) == '*') {
            while ((c = getch()) != EOF && (next = getch()) != EOF) {
                if (c == '*' && next == '/') {
                    break;
                } else {
                    ungetch(next);
                }
            }
            return COMMENT;
        } else if (next == '/') {
            while ((c = getch()) != '\n' && c != EOF);
            return COMMENT;
        } else {
            ungetch(next);
        }
    }

    if (c == '"' || c == '\'') {
        int quote = c;
        while ((c = getch()) != EOF) {
            if (c == '\\') {
                c = getch();
            } else if (c == quote) {
                break;
            }
        }
        return QOUTES;
    }

    if (c == '#') {
        while ((c = getch()) != '\n' && c != EOF);
        return PD;
    }

    if (!isalpha(c) && c != '_') {
        while ((c = getch()) != EOF && c != ' ' && c != '\n');
        return NONE;
    }

    *word++ = c;
    while (--lim > 0) {
        c = getch();
        if (!isalnum(c) && c != '_') {
            ungetch(c);
            break;
        }
        *word++ = c;
    }
    *word = '\0';
    return WORD;
}

int main() {
    return 0;
}
