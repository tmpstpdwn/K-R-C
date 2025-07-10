/*

Exercise 6-6. Implement a simple version of the #define processor (i.e., no arguments)
suitable for use with C programs, based on the routines of this section. You may also find
getch and ungetch helpful.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAX 100
#define BUFSIZE 100

enum TokenType {
  OTHER,
  PD,
  WORD,
  DEFN
};

struct nlist *hashtable[HASHSIZE];

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
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

    while (isspace(c = getch())) {
      if (c == '\n') {
        return OTHER;
      }
    }

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
            return OTHER;
        } else if (next == '/') {
            while ((c = getch()) != '\n' && c != EOF);
            return OTHER;
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
        return OTHER;
    }

    if (c == '#') {
        return PD;
    }

    if (!isalpha(c)) {
        while ((c = getch()) != EOF && c != ' ' && c != '\n');
        return OTHER;
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

enum TokenType getdefn(char *defn, int maxlen) {
  int c, i = 0;
  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c != EOF && c != '\n')
    defn[i++] = c;
  while (i < maxlen - 1 && (c = getch()) != EOF && c != '\n')
    defn[i++] = c;
  defn[i] = '\0';
  return (i)? DEFN: OTHER;
}

unsigned int hash(char *s) {
  unsigned int hashval;
  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31 * hashval;
  }
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
  struct nlist *np;
  for (np = hashtable[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np;
    }
  }
  return NULL;
}

struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned int hashval;
  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *)malloc(sizeof(struct nlist));
    if (np == NULL || (np->name = strdup(name)) == NULL) {
      return NULL;
    } 
    hashval = hash(name);
    np->next = hashtable[hashval];
    hashtable[hashval] = np;
  } else {
    free(np->defn);
  }
  if ((np->defn = strdup(defn)) == NULL) {
    return NULL;
  }
  return np;
}

int main() {
  enum TokenType type;
  enum TokenType pdres;
  enum TokenType nameres;
  enum TokenType defnres;

  char word[MAX];
  char name[MAX];
  char defn[MAX];

  struct nlist *lookupword;

  while ((type = getword(word, MAX)) != EOF) {
    if (type == PD) {
      pdres = getword(word, MAX);
      if (pdres != WORD || strcmp(word, "define") != 0) {
        continue;
      }
      nameres = getword(name, MAX);
      defnres = getdefn(defn, MAX);
      if (nameres == WORD && defnres == DEFN) {
        install(name, defn);
      }
    } else if (type == WORD) {
      lookupword = lookup(word);
      if (lookupword != NULL) {
        printf("%s\n", lookupword->defn);
      } else {
        printf("%s\n", word);
      }
    } 
  }

  return 0;
}
