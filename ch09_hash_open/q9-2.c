/* code: q9-2.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

enum data_status { EMPTY, OCCUPIED, DELETED };

struct student_type {
  int id;
  float average;
  char name[128];
};
typedef struct student_type STUDENT_TYPE;

struct hash_table_type {
  STUDENT_TYPE data;
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
    if (hash_table[new_index].data.id == key) {
      return new_index;
    }
    new_index = (index + i) % TABLE_SIZE;
  }
  return -1;
}

/* ------------------------------------------- */
void hash_table_insert (STUDENT_TYPE data, HASH_TABLE_TYPE hash_table[]) {
  int i, new_index, index;
  int key = data.id;

  index = hash_function (key);
  new_index = index;
  for (i = 1; i != TABLE_SIZE - 1; i++) {
    if (hash_table[new_index].status == EMPTY
	|| hash_table[new_index].status == DELETED) {
      hash_table[new_index].data = data;
      hash_table[new_index].status = OCCUPIED;
      return;
    }
    if (hash_table[new_index].data.id == key) {
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
    printf ("[%03d]:", i);
    if (hash_table[i].status == OCCUPIED) {
      printf ("[%04d, %s, %2.2f]\n",
	      hash_table[i].data.id,
	      hash_table[i].data.name, hash_table[i].data.average);
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
  int i, key, index;
  HASH_TABLE_TYPE hash_table[TABLE_SIZE];
  STUDENT_TYPE data;

  hash_table_init (hash_table);

  srand (1);
  for (i = 0; i < 5; i++) {
    data.id = rand () % 3000;
    data.average = rand () % 100;
    sprintf (data.name, "user_%c", 'a' + i);
    printf ("insert: %d\n", data.id);
    hash_table_insert (data, hash_table);
  }

  hash_table_display (hash_table);

  key = data.id;
  printf ("Search [%d] -> ", key);
  index = hash_table_search (key, hash_table);
  if (i == -1) {
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
