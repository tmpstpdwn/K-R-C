/*

Exercise 7-5. Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do
the input and number conversion.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'
#define LEN 100

static char line[LEN];
static int pos = 0;

char getop(char s[]) {
    int c;

    // Read a new line if buffer is empty or consumed
    if (line[pos] == '\0') {
        if (fgets(line, LEN, stdin) == NULL) {
            return EOF;
        }
        pos = 0;
    }

    // Skip whitespace
    while ((c = line[pos]) == ' ' || c == '\t') pos++;
    s[0] = c = line[pos++];

    s[1] = '\0';

    // Check for 2-char commands like "Pq"
    if (isupper(c)) {
        int t = line[pos++];
        if (islower(t)) {
            s[1] = t;
            s[2] = '\0';
            return c;
        }
        pos--;
        return c;
    }

    // Check for number or sign
    if (isdigit(c) || c == '.' || c == '-' || c == '+') {
        int n;
        if (sscanf(&line[pos - 1], "%s%n", s, &n) == 1) {
            pos = pos - 1 + n;
            return NUMBER;
        }
    }

    return c;
}
