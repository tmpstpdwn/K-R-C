/*Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

double stack[LEN];
int sp = 0;

double pop() {
  return (sp > 0)? stack[--sp]: 0;
}

void push(double x) {
  if (sp < LEN)
    stack[sp++] = x;
}

int isnum(char *s) {
  char *endptr;
  strtod(s, &endptr);
  return *endptr == '\0';
}

int main(int argc, char *argv[]) {
  double op2;
  while (--argc > 0) {
    argv++;
    if (isnum(*argv)) {
        push(atof(*argv));
    } else if (strcmp(*argv, "+") == 0) {
        push(pop() + pop());
    } else if (strcmp(*argv, "-") == 0) {
        op2 = pop();
        push(pop() - op2);
    } else if (strcmp(*argv, "/") == 0) {
        op2 = pop();
        if (op2 != 0)
            push(pop() / op2);
        else {
            printf("Error: division by zero.\n");
            return 1;
        }
    } else if (strcmp(*argv, "*") == 0) {
        push(pop() * pop());
    } else {
        printf("Error: invalid instruction '%s'\n", *argv);
        return 1;
    }
  }
  printf("%f\n", pop());
  return 0;
}
