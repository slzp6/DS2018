/* code: ch11-factorial.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int factorial (int n) {
  int v;

  if (n == 0)
    return 1;

  v = n * factorial (n - 1);

  return v;
}

/* ------------------------------------------- */
int main () {
  int i;

  i = 5;
  printf ("factorial(%d) = %d\n", i, factorial (i));

  return 0;
}
