#include <stdio.h>
#include "utils.h"

static BraceInfo bracestack[LEN];
static int bsp = 0;

void pushbrace(char c, int lineno, int colno) {
    BraceInfo newbrace = {c, lineno, colno};
    if (bsp < LEN) {
        bracestack[bsp++] = newbrace;
    }
}

BraceInfo popbrace(void) {
    return (bsp > 0)? bracestack[--bsp]: (BraceInfo){0};
}

int isopening(char c) {
    return (c == '{' || c == '[' || c == '(');
} 

int isclosing(char c) {
    return (c == '}' || c == ']' || c == ')');
}

char openingof(char c) {
    switch (c) {
        case '}': return '{';
        case ']': return '[';
        case ')': return '(';
        default: return c;
    }
}

int readline(char s[], int max) {
    int i, c;
    for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
    return (c == EOF && i == 0)? -1: i;
}

static int backslashes(const char *line, int colno) {
    int count = 0;
    for (int i = colno - 1; i >= 0 && line[i] == '\\'; i--) {
        count++;
    }
    return count;
}

void handlenclosings(int *enclosings, char *line, int *colno) {
    int c = line[*colno];
    int *instring = &enclosings[INSTRING];
    int *inqoutes = &enclosings[INQUOTES];
    int *incomment = &enclosings[INCOMMENT];

    if (!(*incomment)) {
        if (c == '"' && !(*inqoutes)) {
            int isescaped = (backslashes(line, *colno) % 2);
            if (!isescaped)
                *instring = !(*instring);
        } else if (c == '\'' && !(*instring)) {
            int isescaped = (backslashes(line, *colno) % 2);
            if (!isescaped)
                *inqoutes = !(*inqoutes);
        } 
    } 

    if (!(*instring) && !(*inqoutes)) {
        char t = line[*colno + 1];
        if (c == '/' && t == '*') {
            *incomment = 1;
            *colno += 2;
        } else if (c == '*' && t == '/') {
            *incomment = 0;
            *colno += 2;
        } else if (c == '/' && t == '/') {
            for (*colno += 2; line[*colno] != '\0'; (*colno)++);
        }
    }
}
