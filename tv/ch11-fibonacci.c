/* code: ch11-fibonacci.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int fibonacci (int n) {
  int v;
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  v = fibonacci (n - 1) + fibonacci (n - 2);
  return v;
}

/* ------------------------------------------- */
int main () {
  int i;
  i = 5;

  printf ("Fibonacci(%d) = %d\n", i, fibonacci (i));

  return 0;
}
