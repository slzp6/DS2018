/* code: ch11-gcd.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int gcd (int x, int y) {
  int v;

  if (y == 0)
    return x;

  v = gcd (y, (x % y));

  return v;
}

/* ------------------------------------------- */
int main () {
  int a, b;

  a = 12;
  b = 18;
  printf ("GCD(%d, %d) = %d\n", a, b, gcd (a, b));

  return 0;
}
