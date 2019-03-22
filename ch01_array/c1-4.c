/* code: c1-4.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5000000

int main () {
  int *array;
  int i;

  array = malloc (sizeof (int) * ARRAY_SIZE);

  if (NULL == array) {
    fprintf (stderr, "Error: malloc() \n");
    exit (-1);
  }
  else {
    for (i = 0; i < ARRAY_SIZE; i++) {
      array[i] = rand () % 1000;
    }
    for (i = 0; i < 10; i++) {
      printf ("%d ", array[i]);
    }
    free (array);
  }

  return 0;
}
