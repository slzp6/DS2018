/* code: ch13-qsort-str.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------ */
int cmp_string (const void *p1, const void *p2) {
  return strcmp (*(char *const *) p1, *(char *const *) p2);
}

/* ------------------------------------------ */
void print_str_array (char *v[], int n) {
  int i;
  printf ("array: ");
  for (i = 0; i < n; i++) {
    printf ("%s ", v[i]);
  }
  printf ("\n");
}

/* ------------------------------------------ */
int main () {
  char *array[7] = {
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday", "Friday", "Saturday",
  };
  print_str_array (array, 7);
  qsort (array, 7, sizeof (char *), cmp_string);
  print_str_array (array, 7);
  return 0;
}
