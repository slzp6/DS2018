/* code: c10-2.c   (v1.18.00) */
#include <stdio.h>

/* ------------------------------------------ */
long int hash_kr (char *str) {
  long int hash;
  int c;

  hash = 0;
  while ((c = *str++)) {
    hash += c;
  }
  return hash;
}

/* ------------------------------------------ */
int main () {
  int i;
  char *key[] = {
    "alpha", "bravo", "charlie", "delta",
    "echo", "foxtrot", "golf", "hotel",
    "india", "juliet", "kilo", "lima",
    "mike", "november", "oscar", "papa",
    "quebec", "romeo", "sierra", "tango",
    "uniform", "victor", "whisky", "x-ray",
    "yankee", "zulu"
  };

  for (i = 0; i < 26; i++) {
    printf ("%8s: %ld\n", key[i], hash_kr (key[i]));
  }

  return 0;
}
