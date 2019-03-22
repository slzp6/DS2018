/* code: ch02-stack-str.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DATA_SIZE   100000000
#define MAX         100000000

#define PUSH_SUCCESS    1
#define PUSH_FAILURE   -1
#define POP_SUCCESS     2
#define POP_FAILURE    -2

#define WORDS "/usr/share/dict/words"

/* ------------------------------------------- */
void stack_init (int *top) {
  *top = 0;
}

/* ------------------------------------------- */
void display (char *stack[], int top) {
  int i;
  printf ("STACK(%d): ", top);
  for (i = 0; i < top; i++) {
    printf ("%s ", stack[i]);
  }
  printf ("\n");
}

/* ------------------------------------------- */
int push (char *stack[], int *top, char *data) {
  if (*top >= MAX) {
    /* stack overflow */
    return PUSH_FAILURE;
  }
  else {
    stack[*top] = malloc (sizeof (char) * (strlen (data) + 1));
    sprintf (stack[*top], "%s", data);
    (*top)++;
    return PUSH_SUCCESS;
  }
}

/* ------------------------------------------- */
int pop (char *stack[], int *top, char *data) {
  if ((*top) > 0) {
    sprintf (data, "%s", stack[(*top) - 1]);
    (*top)--;
    return POP_SUCCESS;
  }
  else {
    /* stack empty */
    return POP_FAILURE;
  }
}

/* ------------------------------------------- */
int count_words (char *filename) {
  FILE *infile;
  int i;
  char data[1024];
  if (NULL == (infile = fopen (filename, "rt"))) {
    printf ("ERROR: Can not open file [%s]\n", filename);
    exit (-1);
  }

  i = 0;
  while (EOF != fscanf (infile, "%s", data)) {
    i++;
  }
  fclose (infile);

  return i;
}

/* ------------------------------------------- */
int main () {
  char **stack;
  int top, i, ws;
  FILE *infile;
  char data[1024];

  ws = count_words (WORDS);

  if (NULL == (infile = fopen (WORDS, "rt"))) {
    printf ("ERROR: Can not open file [%s]\n", WORDS);
    exit (-1);
  }

  stack = malloc (sizeof (int) * MAX);

  stack_init (&top);
  i = 0;

  printf ("'%s' (%d)\n", WORDS, ws);
  printf ("push:\n");
  while (EOF != fscanf (infile, "%s", data)) {
    if (i >= ws - 10)
      printf ("%10s (index:%d)\n", data, top);
    push (stack, &top, data);
    i++;
  }
  printf ("\n");

  printf ("pop:\n");
  for (i = 0; i < ws; i++) {
    pop (stack, &top, data);
    if (i < 10)
      printf ("%10s (index:%d)\n", data, top);
  }
  printf ("\n");

  fclose (infile);

  free (stack);


  return 0;
}
