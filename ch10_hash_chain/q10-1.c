/* code: q10-1.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------ */
int is_prime (int number) {
  int i, prime;

  prime = 1;
  if (number < 2)
    return 0;
  for (i = 2; i < number; i++) {
    if ((number % i) == 0) {
      prime = 0;
    }
  }
  return prime;
}

/* ------------------------------------------ */
int main () {
  int i, prime;

  for (i = 0; i < 100; i++) {
    prime = is_prime (i);

    if (prime == 1) {
      printf ("%d ", i);
    }
  }

  return 0;
}
