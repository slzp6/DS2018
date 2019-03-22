/* code: ch13-mergesort-100m.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000
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
void merge_sort (int v[], int lb, int ub, int v_temp[]) {
  int i, j, k, c;

  if (lb >= ub) {
    return;
  }
  c = (lb + ub) / 2;

  merge_sort (v, lb, c, v_temp);
  merge_sort (v, c + 1, ub, v_temp);

  for (i = lb; i <= c; i++) {
    v_temp[i] = v[i];
  }
  for (i = c + 1, j = ub; i <= ub; i++, j--) {
    v_temp[i] = v[j];
  }

  i = lb;
  j = ub;

  for (k = lb; k <= ub; k++) {
    if (v_temp[i] <= v_temp[j]) {
      v[k] = v_temp[i++];
    }
    else {
      v[k] = v_temp[j--];
    }
  }
}

/* ------------------------------------------ */
int main () {
  int *array;
  int *array_temp;


  array = malloc (sizeof (int) * MAX);
  array_temp = malloc (sizeof (int) * MAX);

  if (array == NULL) {
    printf ("ERROR: Can not allocate memory\n");
    exit (-1);
  }

  rand_data (array, MAX);
  printf ("array size: %d\n", MAX);
  fflush (stdout);

  print_array (array, 30);

  merge_sort (array, 0, MAX - 1, array_temp);

  print_array (array, 30);


  free (array_temp);
  free (array);


  return 0;
}
