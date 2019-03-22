/* code: ch11-rec-b.c   (v1.18.00) */
#include <stdio.h>

void foo (int n) {
  if (n < 5) {
    foo (n + 1);
    printf ("%d ", n);
  }
}

int main () {
  foo (0);
  return 0;
}
