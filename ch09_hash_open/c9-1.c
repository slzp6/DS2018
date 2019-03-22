/* code: c9-1.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

enum data_status { EMPTY, OCCUPIED, DELETED };

struct hash_table_type {
  int data;
  enum data_status status;
};
typedef struct hash_table_type HASH_TABLE_TYPE;


/* ------------------------------------------- */
int hash_function (int key) {
  return (key % TABLE_SIZE);
}


/* ------------------------------------------- */
int hash_table_search (int key, HASH_TABLE_TYPE hash_table[]) {
  int i, index, new_index;

  index = hash_function (key);
  new_index = index;
  for (i = 1; i != TABLE_SIZE - 1; i++) {
    if (hash_table[new_index].status == EMPTY) {
      return -1;
    }
    if (hash_table[new_index].data == key) {
      return new_index;
    }
    new_index = (index + i) % TABLE_SIZE;
  }
  return -1;
}

/* ------------------------------------------- */
void hash_table_insert (int data, HASH_TABLE_TYPE hash_table[]) {
  int i, new_index, index;
  int key = data;

  index = hash_function (key);
  new_index = index;
  for (i = 1; i != TABLE_SIZE - 1; i++) {
    if (hash_table[new_index].status == EMPTY
	|| hash_table[new_index].status == DELETED) {
      hash_table[new_index].data = data;
      hash_table[new_index].status = OCCUPIED;
      return;
    }
    if (hash_table[new_index].data == key) {
      return;
    }
    new_index = (index + i) % TABLE_SIZE;
  }
  printf ("ERROR: table size limit exceeded [%d]\n", TABLE_SIZE);
  exit (-1);
}


/* ------------------------------------------- */
void hash_table_delete (int key, HASH_TABLE_TYPE hash_table[]) {
  int new_index = hash_table_search (key, hash_table);
  if (new_index == -1) {
    printf ("Not found\n");
  }
  else {
    hash_table[new_index].status = DELETED;
  }
}


/* ------------------------------------------- */
void hash_table_init (HASH_TABLE_TYPE hash_table[]) {
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
    hash_table[i].status = EMPTY;
  }
}


/* ------------------------------------------- */
void hash_table_display (HASH_TABLE_TYPE hash_table[]) {
  int i;
  printf ("--- hash table ---\n");
  for (i = 0; i < TABLE_SIZE; i++) {
    printf ("[%02d]:", i);
    if (hash_table[i].status == OCCUPIED) {
      printf ("[%03d]\n", hash_table[i].data);
    }
    else if (hash_table[i].status == DELETED) {
      printf ("[deleted]\n");
    }
    else {
      printf ("[empty]\n");
    }
  }
  printf ("------------------\n\n");
}




/* ------------------------------------------- */
int main () {
  int i, key, data, index;
  HASH_TABLE_TYPE hash_table[TABLE_SIZE];

  hash_table_init (hash_table);

  srand (1);
  for (i = 0; i < 5; i++) {
    data = rand () % 1000;
    printf ("insert: %d\n", data);
    hash_table_insert (data, hash_table);
  }

  hash_table_display (hash_table);

  key = data;
  printf ("Search [%d] -> ", key);
  index = hash_table_search (key, hash_table);
  if (index == -1) {
    printf ("Not Found\n");
  }
  else {
    printf ("Found at index:%d\n", index);
  }

  printf ("delete [%d] \n\n", key);
  hash_table_delete (key, hash_table);

  hash_table_display (hash_table);

  return 0;
}
