/* code: ch12-selection-100t-r.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 100000

/* ------------------------------------------ */
void print_array (int v[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf ("%d ", v[i]);
  }
  printf ("\n");
}


/* ------------------------------------------ */
void selection_sort (int v[], int n) {
  int i, j, t, min_index;
  for (i = 0; i < n - 1; i++) {
    min_index = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[min_index]) {
	min_index = j;
      }
    }
    t = v[i];
    v[i] = v[min_index];
    v[min_index] = t;
  }
}

/* ------------------------------------------ */
int main () {
  int *array;
  int i, n;
  clock_t t_start, t_end;

  n = DATA_SIZE;
  array = malloc (sizeof (int) * n);

  for (i = 0; i < n; i++) {
    array[i] = rand () % n;
  }

  printf ("#data:  %d\n", n);
  printf ("input:  ");
  print_array (array, 10);

  t_start = clock ();
  selection_sort (array, n);
  t_end = clock ();

  printf ("output: ");
  print_array (array, 10);
  printf ("time: %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);

  free (array);

  return 0;
}
