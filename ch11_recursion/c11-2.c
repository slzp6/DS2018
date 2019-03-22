/* code: c11-2.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int factorial (int n) {
  int i, v;

  for (i = 0; i < n; i++)
    printf (" ");
  printf ("Called 'factorial(%d)' \n", n);

  if (n == 0)
    return 1;

  v = n * factorial (n - 1);

  for (i = 0; i < n; i++)
    printf (" ");
  printf ("Returning 'factorial(%d)=%d' \n", n, v);
  return v;
}

/* ------------------------------------------- */
int main () {
  int i;

  i = 5;
  printf ("Factorial of %d is %d\n", i, factorial (i));

  return 0;
}
