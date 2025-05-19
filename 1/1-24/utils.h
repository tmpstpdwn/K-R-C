// #DEFINES
#define LEN 100

// ENUMS
enum {INSTRING, INQUOTES, INCOMMENT};

// STRUCTS
typedef struct {
    char brace;
    int lineno;
    int colno;
} BraceInfo;

// utils.c
void pushbrace(char c, int lineno, int colno);
BraceInfo popbrace(void);
int isopening(char c);
int isclosing(char c);
char openingof(char c);
int readline(char s[], int max);
void handlenclosings(int *enclosings, char *line, int *colno);
