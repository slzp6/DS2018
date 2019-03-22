/* code: ch11-power.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int power (int x, int n) {
  int m;
  if (n == 0)
    return 1;

  if (n % 2 == 0) {
    m = power (x, n / 2);
    return m * m;
  }
  else {
    return x * power (x, n - 1);
  }
}

/* ------------------------------------------- */
int main () {
  int x, n;

  x = 5;
  n = 3;
  printf ("power(%d,%d) = %d\n", x, n, power (x, n));

  return 0;
}
