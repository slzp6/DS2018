/* code: q14-4.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

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

/* ------------------------------------------- */
int heap_max (int *v, int n, int i, int j, int k) {
  int max;

  max = i;
  if ((j < n) && (v[j] > v[max])) {
    max = j;
  }
  if ((k < n) && (v[k] > v[max])) {
    max = k;
  }
  return max;
}

/* ------------------------------------------- */
void downheap (int *v, int n, int i) {
  int left, right, j, temp;
  while (1) {
    left = 2 * i + 1;
    right = 2 * i + 2;
    j = heap_max (v, n, i, left, right);
    if (j == i) {
      break;
    }
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    i = j;
  }
}

/* ------------------------------------------- */
void heapsort (int *v, int n) {
  int i, temp;
  for (i = (n - 2) / 2; i >= 0; i--) {
    downheap (v, n, i);
  }
  for (i = 0; i < n; i++) {
    temp = v[n - i - 1];
    v[n - i - 1] = v[0];
    v[0] = temp;
    downheap (v, n - i - 1, 0);
  }
}


/* ------------------------------------------ */
void rand_data (int v[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    v[i] = rand () % (MAX / 10);
  }
}


/* ------------------------------------------- */
int main () {
  int *array;
  struct timeval start, end;
  double elapsed_in_seconds;

  array = malloc (sizeof (int) * MAX);
  rand_data (array, MAX);
  print_array (array, 20);

  gettimeofday (&start, NULL);
  heapsort (array, MAX);
  gettimeofday (&end, NULL);

  print_array (array, 20);

  elapsed_in_seconds = difftime (end.tv_sec, start.tv_sec) +
    difftime (end.tv_usec, start.tv_usec) / 1000000.0;
  printf ("%lf seconds\n", elapsed_in_seconds);
  free (array);
  return 0;
}
