/* code: ch13-qsort.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------ */
void print_array (int v[], int n) {
  int i;
  printf ("array: ");
  for (i = 0; i < n; i++) {
    printf ("%02d ", v[i]);
  }
  printf ("\n");
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
  int array[10]
  = { 80, 40, 30, 20, 10, 00, 70, 90, 50, 60 };

  print_array (array, 10);
  qsort (array, 10, sizeof (int), int_compare);
  print_array (array, 10);

  return 0;
}
