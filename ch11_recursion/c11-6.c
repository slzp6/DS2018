/* code: c11-6.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int gcd (int x, int y) {
  int v;

  printf ("Called 'gcd(%d,%d)' \n", x, y);

  if (y == 0)
    return x;

  v = gcd (y, (x % y));

  printf ("Returning 'gcd(%d,%d)=%d' \n", x, y, v);

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
