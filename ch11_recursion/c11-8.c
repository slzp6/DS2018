/* code: c11-8.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int factorial (int n) {
  if (n == 0)
    return 1;

  return n * factorial (n - 1);
}

/* ------------------------------------------- */
int factorial_tail (int n, int acc) {
  if (n == 0)
    return acc;

  return factorial_tail (n - 1, n * acc);
}

/* ------------------------------------------- */
int main () {
  int i;

  i = 5;
  printf ("factorial_tail(%d) = %d\n", i, factorial_tail (i, 1));

  return 0;
}
