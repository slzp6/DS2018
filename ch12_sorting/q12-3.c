/* code: q12-3.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

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
void bubble_sort (int v[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
	temp = v[j];
	v[j] = v[j + 1];
	v[j + 1] = temp;
      }
    }
  }
}


/* ------------------------------------------ */
int main () {
  int *array;
  int i, n;

  n = 100000;
  array = malloc (sizeof (int) * n);

  for (i = 0; i < n; i++) {
    array[i] = rand () % n;
  }

  print_array (array, 10);
  bubble_sort (array, n);
  print_array (array, 10);

  free (array);

  return 0;
}
