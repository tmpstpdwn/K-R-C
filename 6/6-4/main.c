/*

Exercise 6-4. Write a program that prints the distinct words in its input sorted into decreasing
order of frequency of occurrence. Precede each word by its count.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

enum TokenType {
    NONE,
    WORD
};

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

enum TokenType getword(char *word, int lim) {
    int c;
    *word = '\0';

    while (isspace(c = getchar()));

    if (c == EOF) {
        return EOF;
    }

    if (!isalpha(c)) {
      return NONE;
    }

    *word++ = c;
    while (--lim > 0 && isalpha(c = getchar())) {
        *word++ = c;
    }

    if (c != EOF) {
        ungetc(c, stdin);
    }

    *word = '\0';
    return WORD;
}

void to_lower_word(char *word) {
    for (; *word; ++word) {
        *word = tolower((unsigned char)*word);
    }
}

struct tnode *addtree(struct tnode *p, char *word, int *count) {
  int cmp;
  if (p == NULL) {
    p = (struct tnode *)malloc(sizeof(struct tnode));
    if (p == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    (*count)++;
    p->word = strdup(word);
    p->left = p->right = NULL;
    p->count = 1;
  } else {
    int cmp = strcmp(word, p->word);
    if (cmp < 0) {
      p->left = addtree(p->left, word, count);
    } else if (cmp > 0) {
      p->right = addtree(p->right, word, count);
    } else {
      p->count++;
    }
  }
  return p;
}

void tree_to_array(struct tnode *p, struct tnode **array, int *index) {
  if (p != NULL) {
    tree_to_array(p->left, array, index);
    array[(*index)++] = p;
    tree_to_array(p->right, array, index);
  }
}

int compare(const void *a, const void *b) {
    struct tnode *node1 = *(struct tnode **)a;
    struct tnode *node2 = *(struct tnode **)b;
    return node2->count - node1->count;
}

void free_tree(struct tnode *p) {
    if (p != NULL) {
        free_tree(p->left);
        free_tree(p->right);
        free(p->word);
        free(p);
    }
}

int main(int argc, char **argv) {
  enum TokenType type;
  char word[MAX];

  struct tnode *array[MAX];
  int count = 0;

  int index = 0;

  struct tnode *root = NULL;
  
  while ((type = getword(word, MAX)) != EOF) {
      if (type == WORD && strlen(word) > 1) {
          to_lower_word(word);
          root = addtree(root, word, &count);
      }
  }

  tree_to_array(root, array, &index);

  qsort(array, count, sizeof(struct tnode *), compare);

  for (int i = 0; i < count; i++) {
      printf("%s : %d\n", array[i]->word, array[i]->count);
  }

  free_tree(root);

  return 0;
}
