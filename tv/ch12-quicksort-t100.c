/* code: ch12-quicksort-t100.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 100000

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
void print_array (int v[], int n) {
  int i;

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
void bubble_sort2 (int v[], int n) {
  int i, j, temp, flag;

  flag = 1;
  for (i = 0; (i < n - 1) && (flag == 1); i++) {
    flag = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
	temp = v[j];
	v[j] = v[j + 1];
	v[j + 1] = temp;
	flag = 1;
      }
    }
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

  array = malloc (sizeof (int) * n);

  for (i = 0; i < n; i++) {
    array[i] = rand () % n;
  }

  printf ("#data:  %d\n", n);
  printf ("input:  ");
  print_array (array, 10);

  t_start = clock ();
  quicksort (array, 0, n - 1);
  t_end = clock ();

  printf ("output: ");
  print_array (array, 10);
  printf ("time: %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);

  free (array);

  return 0;
}
