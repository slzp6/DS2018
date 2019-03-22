/* code: q1-4.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <search.h>

#define ARRAY_SIZE 100000000

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
  int i, key;
  int *r;
  int *array;

  array = malloc (sizeof (int) * ARRAY_SIZE);

  printf ("random numbers (%d) ... ", ARRAY_SIZE);
  fflush (stdout);
  for (i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand ();
  }
  printf ("done\n");
  fflush (stdout);

  printf ("sorting (%d) ... ", ARRAY_SIZE);
  fflush (stdout);
  qsort (array, ARRAY_SIZE, sizeof (int), int_compare);
  printf ("done\n");
  fflush (stdout);

  key = array[5];
  print_array (array, 10);

  printf ("bsearch (%d)\n", ARRAY_SIZE);
  fflush (stdout);
  r = (int *) bsearch (&key, array, ARRAY_SIZE, sizeof (int), int_compare);

  if (r != NULL) {
    printf ("Found: %d\n", key);
  }
  else {
    printf ("Not found: %d\n", key);
  }
  fflush (stdout);

  free (array);

  return 0;
}
