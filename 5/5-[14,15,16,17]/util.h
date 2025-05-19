// #DEFINES.
#define MAX 5000

// lines.c
int readlines(char **s, int nlines);
void writelines(char **s, int nlines);
void reverselines(char **s, int nlines);
const char *fieldpointer(const char *s, int n);
int fieldlen(const char *s);
void filterlines(char *line);

// qsort.c
int numcmp(const char *s1, const char *s2, int field);
int strcmpnorm(const char *s1, const char *s2, int field);
int strcmplow(const char *s1, const char *s2, int field);
void qsortc(void **v, int left, int right, int (*comp)(void *, void *, int), int field);

