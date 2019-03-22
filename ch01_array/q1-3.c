/* code: q1-3.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <search.h>

#define ARRAY_SIZE 10

/* ------------------------------------------ */
int int_compare (const void *va, const void *vb) {
  int a, b;
  a = *(int *) va;
  b = *(int *) vb;
  if (a < b) {
    return (-1);
  }
  else if (a > b) {
    return (1);
  }
  else {
    return (0);
  }
}

/* ------------------------------------------- */
void print_array (int array[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf ("%d ", array[i]);
  }
  printf ("\n");
}

/* ------------------------------------------- */
int main () {
  int key;
  int *r;
  int array[ARRAY_SIZE] = {
    10, 12, 16, 19, 28, 30, 38, 44, 70, 98
  };
  /* ordered array! */

  key = 16;
  print_array (array, ARRAY_SIZE);

  r = (int *) bsearch (&key, array, ARRAY_SIZE, sizeof (int), int_compare);
  if (r != NULL) {
    printf ("Found: %d\n", key);
  }
  else {
    printf ("Not found: %d\n", key);
  }
  return 0;
}
