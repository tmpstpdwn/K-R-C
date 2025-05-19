#include <stdio.h>
#include "rpc.h"

static double stack[LEN];
static int sp = 0;

// Push x to stack.
void push(double x) {
  if (sp < LEN) {
    stack[sp++] = x;
  } else {
    printf("Error: Stack full\n");
  }
}

// Pop from stack.
double pop(void) {
  if (sp > 0) {
    return stack[--sp];
  } else {
    return 0.0;
  }
}

// Clear the stack.
void clear(void) {
  sp = 0;
}

// Return the top element on stack without popping.
double rtop(void) {
  return (sp > 0)? stack[sp - 1]: 0;
}

/*
// Duplicate top element on stack and push it back.
void dupe(void) {
  if (sp > 0) 
    push(stack[sp - 1]);
  else 
    printf("Error: stack empty\n");
}

// Swap top 2 elements on stack.
void swap(void) {
  if (sp > 1) {
    double t = stack[sp - 1];
    stack[sp - 1] = stack[sp - 2];
    stack[sp - 2] = t;
  } else {
    printf("Error: No elements to swap\n");
  }
}
*/
