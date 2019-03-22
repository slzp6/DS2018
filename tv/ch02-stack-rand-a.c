/* code: ch02-stack-rand-a.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>

#define DATA_SIZE   30
#define MAX         30

#define PUSH_SUCCESS    1
#define PUSH_FAILURE   -1
#define POP_SUCCESS     2
#define POP_FAILURE    -2

/* ------------------------------------------- */
void stack_init (int *top) {
  *top = 0;
}

/* ------------------------------------------- */
void display (int stack[], int top) {
  int i;
  printf ("STACK(%2d): ", top);
  for (i = 0; i < top; i++) {
    printf ("%d ", stack[i]);
  }
  printf ("\n");
}

/* ------------------------------------------- */
int push (int stack[], int *top, int data) {
  if (*top >= MAX) {
    /* stack overflow */
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
int main () {
  int *stack;
  int top, data, i;

  stack = malloc (sizeof (int) * MAX);
  printf ("data size: %d\n", DATA_SIZE);
  stack_init (&top);

  for (i = 0; i < DATA_SIZE; i++) {
    data = rand () % 1000;
    if (data > 500) {
      push (stack, &top, data);
    }
    else {
      pop (stack, &top, &data);
    }
    display (stack, top);
  }
  printf ("\n");

  free (stack);

  return 0;
}
