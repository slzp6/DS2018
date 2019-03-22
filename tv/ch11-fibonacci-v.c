/* code: ch11-fibonacci-v.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------- */
int fibonacci (int n) {
  int i, v;

  for (i = 0; i < n; i++)
    printf (" ");
  printf ("Called 'fibonacci(%d)' \n", n);

  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  v = fibonacci (n - 1) + fibonacci (n - 2);

  for (i = 0; i < n; i++)
    printf (" ");
  printf ("Returning 'fibonacci(%d)=%d' \n", n, v);
  return v;
}

/* ------------------------------------------- */
int main () {
  int i;
  i = 5;
  printf ("Fibonacci(%d) = %d\n", i, fibonacci (i));

  return 0;
}
