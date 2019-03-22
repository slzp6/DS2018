/* code: q11-4.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 13

/* ------------------------------------------- */
int binary_search (int array[], int num, int key) {
  int middle, low, high;
  low = 0;
  high = num - 1;
  while (low <= high) {
    middle = (low + high) / 2;
    if (key == array[middle]) {
      return middle;
    }
    else if (key < array[middle]) {
      high = middle - 1;
    }
    else {
      low = middle + 1;
    }
  }
  return -1;
}


/* ------------------------------------------- */
int binary_search_r (int array[], int num, int key, int low, int high) {
  int middle;

  if (low > high)
    return -1;

  middle = (low + high) / 2;

  if (array[middle] == key) {
    return middle;
  }
  else if (array[middle] < key) {
    return binary_search_r (array, num, key, middle + 1, high);
  }
  else {
    return binary_search_r (array, num, key, low, middle - 1);
  }
}


/* ------------------------------------------- */
void print_array (int array[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf ("%d ", array[i]);
  }
  printf ("\n");
}

/* ------------------------------------------- */
int main () {
  int index, key;
  int array[ARRAY_SIZE] = {
    50, 80, 150, 210, 250, 280, 330,
    470, 510, 530, 800, 900, 990
  };

  key = 800;
  print_array (array, ARRAY_SIZE);

  /* index = binary_search (array, ARRAY_SIZE, key); */

  index = binary_search_r (array, ARRAY_SIZE, key, 0, ARRAY_SIZE - 1);

  if (index != -1) {
    printf ("Found: %d (index:%d)\n", key, index);
  }
  else {
    printf ("Not found: %d\n", key);
  }
  return 0;
}
