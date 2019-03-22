/* code: ch13-qsort-100t.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

/* ------------------------------------------ */
void print_array (int v[], int n) {
  int i;
  printf ("array: ");
  for (i = 0; i < n; i++) {
    printf ("%d ", v[i]);
  }
  printf ("\n");
}

/* ------------------------------------------ */
void rand_data (int v[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    v[i] = rand () % (MAX / 10);
  }
}

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

/* ------------------------------------------ */
int main () {
  int *array;

  array = malloc (sizeof (int) * MAX);

  rand_data (array, MAX);
  printf ("array size: %d\n", MAX);
  fflush (stdout);

  print_array (array, 10);
  qsort (array, MAX, sizeof (int), int_compare);
  print_array (array, 10);

  free (array);

  return 0;
}
