/* code: ch14-heap-10.c   (v1.18.00) */
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

/* ------------------------------------------- */
int main () {
  int array[10]
  = { 80, 40, 30, 20, 10, 00, 70, 90, 50, 60 };

  print_array (array, 10);
  heapsort (array, 10);
  print_array (array, 10);

  return 0;
}
