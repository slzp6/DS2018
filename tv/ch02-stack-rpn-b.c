/* code: ch02-stack-rpn-b.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX           1024

#define PUSH_SUCCESS    1
#define PUSH_FAILURE   -1
#define POP_SUCCESS     2
#define POP_FAILURE    -2
/* ------------------------------------------- */
void stack_init (int *top) {
  *top = 0;
}


/* ------------------------------------------- */
int push (int stack[], int *top, int data) {
  if (*top >= MAX) {
    /* stack overflodelim */
    return PUSH_FAILURE;
  }
  else {
    stack[*top] = data;
    (*top)++;
    return PUSH_SUCCESS;
  }
}

/* ------------------------------------------- */
int pop (int stack[], int *top, int *data) {
  if ((*top) > 0) {
    *data = stack[(*top) - 1];
    (*top)--;
    return POP_SUCCESS;
  }
  else {
    /* stack empty */
    return POP_FAILURE;
  }
}

/* ------------------------------------------- */
int rpn (char *str) {
  int stack[MAX];
  int top, i;
  int a, b;
  char *endptr;
  char *delim = " \n\t\r\f";

  a = b = 0;
  stack_init (&top);

  for (str = strtok (str, delim); str; str = strtok (0, delim)) {
    a = (int) strtod (str, &endptr);
    if (endptr > str) {
      printf ("n: ");
      push (stack, &top, a);
    }
    else if (*str == '+') {
      printf ("%c: ", *str);
      pop (stack, &top, &b);
      pop (stack, &top, &a);
      push (stack, &top, (a + b));
    }
    else if (*str == '-') {
      printf ("%c: ", *str);
      pop (stack, &top, &b);
      pop (stack, &top, &a);
      push (stack, &top, (a - b));
    }
    else if (*str == '*') {
      printf ("%c: ", *str);
      pop (stack, &top, &b);
      pop (stack, &top, &a);
      push (stack, &top, (a * b));
    }
    else if (*str == '/') {
      printf ("%c: ", *str);
      pop (stack, &top, &b);
      pop (stack, &top, &a);
      push (stack, &top, (a / b));
    }
    else {
      fprintf (stderr, "[%c]: ", *str);
      fprintf (stderr, "unknown oeprators\n");
    }

    for (i = 0; i < top; i++) {
      printf (" %d", stack[i]);
    }
    printf ("\n");
  }

  if (top != 1) {
    fprintf (stderr, "stack error\n");
    exit (-1);
  }

  pop (stack, &top, &a);
  return a;
}


/* ------------------------------------------- */
int main () {
  int result;

  //    ( 50 + 30 ) * 100 / 20 - 300 * 2 + 300
  char rpn_str[] = " 50 30 + 100 * 20 / 300 2 * - 300 + ";

  printf ("RPN expression: %s\n\n", rpn_str);
  result = rpn (rpn_str);
  printf ("\n");
  printf ("result: %d\n", result);
  return 0;
}
