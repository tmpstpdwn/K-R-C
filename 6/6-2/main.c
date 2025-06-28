/*

Exercise 6-2. Write a program that reads a C program and prints in alphabetical order each
group of variable names that are identical in the first 6 characters, but different somewhere
thereafter. Don't count words within strings and comments. Make 6 a parameter that can be
set from the command line.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CMP_LEN 6
#define MAXWORD 100
#define BUFSIZE 100

enum TokenType {
    NONE,
    COMMENT,
    QOUTES,
    PD,
    WORD
};

struct tnode {
  char *word;
  struct tnode *left;
  struct tnode *right;
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

void to_lower_word(char *word) {
    for (; *word; ++word) {
        *word = tolower((unsigned char)*word);
    }
}

void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%s\n", p->word);
    treeprint(p->right);
    free(p->word);
    free(p);
  }
}

struct tnode *addtree(struct tnode *p, char *word, int n) {
  int cmp;
  if (p == NULL) {
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->word = strdup(word);
    p->left = p->right = NULL;
  } else {
      cmp = strncmp(word, p->word, n);
      cmp = (cmp == 0)? strcmp(word, p->word): cmp;
      if (cmp > 0) {
          p->right = addtree(p->right, word, n);
      } else if (cmp < 0) {
          p->left = addtree(p->left, word, n);
      }
  }
  return p;
}

int main(int argc, char **argv) {
  int n = 0;
  enum TokenType type;
  char word[MAXWORD];
  struct tnode *root = NULL;
  
  if (--argc >= 1)
    n = (atoi(*++argv)); 
  n = (n != 0)? n: CMP_LEN;

  while ((type = getword(word, MAXWORD)) != EOF) {
      if (type == WORD && strlen(word) > 1) {
          to_lower_word(word);
          root = addtree(root, word, n);
      }
  }

  treeprint(root);

  return 0;
}
