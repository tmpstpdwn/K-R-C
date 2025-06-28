/*

Exercise 6-5. Write a function undef that will remove a name and definition from the table
maintained by lookup and install

*/

#include <stdio.h>

#define HASHSIZE 101

static struct nlist *hashtable[HASHSIZE];

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

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
    np = (struct nlist *)malloc(sizeof(nlist));
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
  return 0;
}
