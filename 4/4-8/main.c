/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.*/

#include <stdio.h>

static char buf = 0;
static int has_buf = 0;

int getch(void) {
    if (has_buf) {
        has_buf = 0;
        return buf;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (has_buf) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
        has_buf = 1;
    }
}
