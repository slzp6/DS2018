/* code: ch12-bubble-100t-o50.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 100000
#define ORDERED   0.50
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
int main () {
  int *array;
  int i, n;
  float ord;
  clock_t t_start, t_end;

  n = DATA_SIZE;
  ord = ORDERED;
  array = malloc (sizeof (int) * n);

  for (i = 0; i < n; i++) {
    array[i] = rand () % n;
  }
  qsort (array, n * ord, sizeof (int), int_compare);


  printf ("#data:  %d  (o:%.2f%%)\n", n, ord * 100.0);
  printf ("input:  ");
  print_array (array, 10);

  t_start = clock ();
  bubble_sort (array, n);
  t_end = clock ();

  printf ("output: ");
  print_array (array, 10);
  printf ("time: %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);

  free (array);

  return 0;
}
