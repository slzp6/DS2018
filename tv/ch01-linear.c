/* code: ch01-linear.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRN  0
#define ARRAY_SIZE 300000


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
void shuffle (int *v, int n) {
  int i, j, t;
  for (i = 0; i < n; i++) {
    j = rand () % n;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
  }
}

/* ------------------------------------------ */
void rand_nd (int *v, int n) {
  int i;
  for (i = 0; i < n; i++) {
    v[i] = i;
  }
  shuffle (v, n);
}


/* ------------------------------------------- */
int linear_search (int array[], int n, int key) {
  int i;
  for (i = 0; i < n; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}


/* ------------------------------------------- */
int binary_search (int array[], int num, int key) {
  int middle, low, high;
  low = 0;
  high = num - 1;
  while (low <= high) {
    middle = (low + high) / 2;
    if (key == array[middle]) {
      return middle;
    }
    else if (key < array[middle]) {
      high = middle - 1;
    }
    else {
      low = middle + 1;
    }
  }
  return -1;
}

/* ------------------------------------------- */
void print_array (int array[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf ("%d ", array[i]);
  }
  printf ("\n");
  fflush (stdout);
}

/* ------------------------------------------- */
int main () {
  int index, key, i, df, dn;
  int *array;
  clock_t t1_start, t1_end;

  array = malloc (sizeof (int) * ARRAY_SIZE);

  rand_nd (array, ARRAY_SIZE);

  print_array (array, 10);

  printf ("\n");
  printf ("linear search (%d)  ", ARRAY_SIZE);
  fflush (stdout);

  df = 0;
  dn = 0;
  t1_start = clock ();
  for (i = 0; i < ARRAY_SIZE; i++) {

    key = rand () % (ARRAY_SIZE * 2);
    index = linear_search (array, ARRAY_SIZE, key);


    if (index != -1) {
      if (PRN)
	printf ("Found: %d (index:%d)\n", key, index);
      df++;
    }
    else {
      if (PRN)
	printf ("Not found: %d\n", key);
      dn++;
    }
    if (!(i % (ARRAY_SIZE / 10))) {
      printf ("*");
      fflush (stdout);
    }
  }
  t1_end = clock ();

  printf ("\n");
  printf ("found: %d   not_found: %d\n", df, dn);
  printf ("time: %.3lf sec.\n",
	  (double) (t1_end - t1_start) / (double) CLOCKS_PER_SEC);


  free (array);
  return 0;
}
