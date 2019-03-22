/* code: ch13-quicksort-100t-r.c   (v1.18.00) */
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
void rand_data (int v[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    v[i] = rand () % (DATA_SIZE / 10);
  }
}

/* ------------------------------------------ */
int partition (int v[], int lower_bound, int upper_bound) {
  int a, down, up, temp;

  a = v[lower_bound];
  up = upper_bound;
  down = lower_bound;

  while (down < up) {
    while ((v[down] <= a) && (down < upper_bound)) {
      down++;
    }
    while (v[up] > a) {
      up--;
    }
    if (down < up) {
      temp = v[down];
      v[down] = v[up];
      v[up] = temp;
    }
  }
  v[lower_bound] = v[up];
  v[up] = a;
  return up;
}

/* ------------------------------------------ */
void quicksort (int v[], int left, int right) {
  int p;
  if (left >= right) {
    return;
  }
  p = partition (v, left, right);
  quicksort (v, left, p - 1);
  quicksort (v, p + 1, right);
}

/* ------------------------------------------ */
int main () {
  int *array;
  int i, n;
  clock_t t_start, t_end;

  n = DATA_SIZE;
  array = malloc (sizeof (int) * DATA_SIZE);
  for (i = 0; i < n; i++) {
    array[i] = rand () % n;
  }

  // rand_data (array, DATA_SIZE);
  printf ("#data:  %d\n", DATA_SIZE);
  fflush (stdout);

  printf ("input:  ");
  print_array (array, 10);

  t_start = clock ();
  quicksort (array, 0, DATA_SIZE - 1);
  t_end = clock ();

  printf ("output: ");
  print_array (array, 10);
  printf ("time: %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);
  free (array);

  return 0;
}
