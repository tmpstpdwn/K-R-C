/*

Exercise 6-3. Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
``and,'' and so on.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100

enum TokenType {
    NONE,
    WORD,
    NEWLINE
};

struct LineNode {
  int num;
  struct LineNode *next;
};

struct WordNode {
  char *word;
  struct LineNode *lines;
  struct WordNode *next;
};

const char *noise_words[] = {
    "the", "and", "a", "an", "of", "to", "in", "that", "is", "it", "if", "on", "for", "so", NULL
};

int is_noise_word(const char *word) {
    for (int i = 0; noise_words[i] != NULL; i++) {
        if (strcmp(word, noise_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void to_lower_word(char *word) {
    for (; *word; ++word) {
        *word = tolower((unsigned char)*word);
    }
}

enum TokenType getword(char *word, int lim) {
    int c;
    *word = '\0';

    while (isspace(c = getchar())) {
        if (c == '\n') {
            return NEWLINE;
        }
    }

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

struct LineNode *addline(struct LineNode *p, int lineno) {
    struct LineNode *curr = p;

    while (curr != NULL) {
        if (curr->num == lineno) {
            return p;
        }
        curr = curr->next;
    }

    struct LineNode *new_node = malloc(sizeof(struct LineNode));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    new_node->num = lineno;
    new_node->next = p;
    return new_node;
}

struct WordNode *addword(struct WordNode *p, char *word, int lineno) {
    struct WordNode *curr = p;

    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            curr->lines = addline(curr->lines, lineno);
            return p;
        }
        curr = curr->next;
    }

    struct WordNode *new_node = malloc(sizeof(struct WordNode));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    new_node->word = strdup(word);
    if (new_node->word == NULL) {
        perror("Failed to allocate memory for word");
        free(new_node);
        exit(EXIT_FAILURE);
    }

    new_node->lines = addline(NULL, lineno);
    new_node->next = p;
    return new_node;
}

void print_word_list(struct WordNode *root) {
    struct WordNode *curr_word = root;

    while (curr_word != NULL) {
        printf("%s: ", curr_word->word);

        struct LineNode *curr_line = curr_word->lines;
        while (curr_line != NULL) {
            printf("%d ", curr_line->num);
            curr_line = curr_line->next;
        }

        printf("\n");
        curr_word = curr_word->next;
    }
}

int main() {
    enum TokenType type;
    char word[MAXWORD];
    int lineno = 1;
    struct WordNode *root = NULL;

    while ((type = getword(word, MAXWORD)) != EOF) {
        if (type == WORD && strlen(word) > 1) {
            tolower_word(word);
            if (!is_noise_word(word)) {
                root = addword(root, word, lineno);
            }
        } else if (type == NEWLINE) {
            lineno++;
        }
    }

    print_word_list(root);

    return 0;
}
