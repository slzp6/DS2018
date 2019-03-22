/* code: ch11-rec-a.c   (v1.18.00) */
#include <stdio.h>

void foo (int n) {
  if (n < 5) {
    printf ("%d ", n);
    foo (n + 1);
  }
}

int main () {
  foo (0);
  return 0;
}
