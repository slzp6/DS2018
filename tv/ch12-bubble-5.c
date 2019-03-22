/* code: ch12-bubble-5.c   (v1.18.00) */
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
      printf ("i:%d j:%d  ", i, j);
      print_array (v, n);
    }
  }
}

/* ------------------------------------------ */
int main () {
  int array[5]
  = { 300, 100, 200, 500, 400 };

  print_array (array, 5);
  bubble_sort (array, 5);
  print_array (array, 5);

  return 0;
}
