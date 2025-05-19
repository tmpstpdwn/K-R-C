/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)*/

#include <stdio.h>
#include "utils.h"

int main(void) {

    char line[LEN];

    int len, colno, lineno;
    int quit;
    char c;

    int enclosings[3] = {0};

    quit = lineno = 0;

    while ((len = readline(line, LEN)) >= 0) {

        colno = 0;
        lineno++;

        while ((c = line[colno]) != '\0') {

            handlenclosings(enclosings, line, &colno);

            if (line[colno] == '\0') {
                continue;
            }

            if (enclosings[INSTRING] || enclosings[INQUOTES] || enclosings[INCOMMENT]) {
                colno++;
                continue;
            }

            if (isopening(c)) {
                pushbrace(c, lineno, colno + 1);
            } else if (isclosing(c)) {
                char lastbrace = popbrace().brace;
                if (!(lastbrace == openingof(c))) {
                    quit = 1;
                    printf("Mismatch: \'%c\' found for \'%c\' at line: %d, col: %d.\n", c, lastbrace, lineno, colno + 1);
                    break;
                }
            }

            colno++;
        }

        if (quit) break;
    }

    if (!quit) {
        BraceInfo b;
        while ((b = popbrace()).brace) {
            printf("Unclosed: '%c' at line: %d, col: %d.\n", b.brace, b.lineno, b.colno);
        }
    }

    return 0;
}
