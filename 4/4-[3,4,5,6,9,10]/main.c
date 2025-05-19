/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.*/

/*Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.*/

/*Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.*/

/*Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.*/

/*Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.*/

/*Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "rpc.h"

int main() {

  int type;
  double op2;
  char s[LEN]; // for buffering numbers and commands.
  double vars[26] = {0}; // for storing variable data.

  printf("\nReverse Polish Calculator\n-------------------------\n\n");

  while ((type = getop(s)) != EOF) {
    switch (type) {

      // Push number.
      case NUMBER:
        push(atof(s));
        break;

      // Arithmetic operations.
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
            printf("Error: Division by 0.\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        else
            printf("Error: Division by 0.\n");
        break;

      // Other functions.
      case 'F':
        if (s[1] == 's') {
            push(sin(pop()));
        } else if (s[1] == 'e') {
            push(exp(pop()));
        } else if (s[1] == 'p') {
            op2 = pop();
            push(pow(pop(), op2));
        }
        break;

      // Store to vars.
      case 'V':
        vars[s[1] - 'a'] = rtop();
        break;

      // Newline.
      case '\n':
        printf("%f\n\n", pop());
        clear();
        break;

      // Default.
      default:
        if (islower(type)) {
          push(vars[(type - 'a')]);
        } else {
          printf("Error: Unknown command.\n");
        }
        break;
    }
  }

  printf("Over.\n\n");

  return 0;

}
