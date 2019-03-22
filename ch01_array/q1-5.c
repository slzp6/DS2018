/* code: q1-5.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

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

/* ------------------------------------------ */
int main () {
  int i, n;
  int *v;

  n = 10;
  v = malloc (sizeof (int) * n);

  rand_nd (v, n);

  for (i = 0; i < n; i++)
    printf ("%d ", v[i]);

  free (v);
  return 0;
}
