/* code: q10-5.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_ERROR (-1)
#define DATA_SIZE 26
#define HASH_TABLE_SIZE 29

struct hash_node_type {
  int data;
  char *key;
  struct hash_node_type *next;
};
typedef struct hash_node_type HASH_NODE;


struct hash_table_type {
  struct hash_node_type **bucket;
  int size;
  int num;
};
typedef struct hash_table_type HASH_TABLE;

/* ------------------------------------------- */
int hash_function (HASH_TABLE * table, char *key) {
  int hash;
  int c;

  hash = 0;
  while ((c = *key++)) {
    hash += c;
  }

  return hash % table->size;
}

/* ------------------------------------------- */
void hash_table_init (HASH_TABLE * table, int table_size) {
  table->num = 0;
  table->size = table_size;
  table->bucket = calloc (table->size, sizeof (HASH_NODE *));
}

/* ------------------------------------------- */
int hash_table_search (HASH_TABLE * table, char *key) {
  int h;
  HASH_NODE *node;

  h = hash_function (table, key);
  for (node = table->bucket[h]; node != NULL; node = node->next) {
    if (!strcmp (node->key, key)) {
      break;
    }
  }

  if (node) {
    return node->data;
  }
  else {
    return HASH_TABLE_ERROR;
  }
}

/* ------------------------------------------- */
int hash_table_insert (HASH_TABLE * table, char *key, int data) {
  int tmp;
  HASH_NODE *node;
  int h;

  if ((tmp = hash_table_search (table, key)) != HASH_TABLE_ERROR) {
    return (tmp);
  }

  h = hash_function (table, key);
  node = malloc (sizeof (HASH_NODE));
  node->data = data;
  node->key = key;
  node->next = table->bucket[h];
  table->bucket[h] = node;
  table->num++;

  return HASH_TABLE_ERROR;
}

/* ------------------------------------------- */
int hash_table_delete (HASH_TABLE * table, char *key) {
  HASH_NODE *node, *node_temp;
  int data;
  int h;

  h = hash_function (table, key);
  for (node = table->bucket[h]; node; node = node->next) {
    if (!strcmp (node->key, key))
      break;
  }

  if (node == NULL)
    return HASH_TABLE_ERROR;

  if (node == table->bucket[h]) {
    table->bucket[h] = node->next;
  }
  else {
    for (node_temp = table->bucket[h]; node_temp && node_temp->next;
	 node_temp = node_temp->next) {
      if (node_temp->next == node)
	break;
    }
    node_temp->next = node->next;
  }
  data = node->data;
  free (node);
  return (data);
}

/* ------------------------------------------- */
void hash_table_free (HASH_TABLE * table) {
  HASH_NODE *node, *node_temp;
  int i;

  for (i = 0; i < table->size; i++) {
    node = table->bucket[i];
    while (node != NULL) {
      node_temp = node;
      node = node->next;
      free (node_temp);
    }
  }

  if (table->bucket != NULL) {
    free (table->bucket);
    memset (table, 0, sizeof (HASH_TABLE));
  }
}

/* ------------------------------------------- */
void hash_table_display (HASH_TABLE * table) {
  HASH_NODE *node;
  int i;
  printf ("------------------------\n");
  for (i = 0; i < table->size; i++) {
    printf ("%02d: ", i);
    node = table->bucket[i];
    while (node != NULL) {
      printf ("%2d(%s) ", node->data, node->key);
      node = node->next;
    }
    printf ("\n");
  }
  printf ("------------------------\n");
}

/* ------------------------------------------- */
void hash_table_info (HASH_TABLE * table) {
  printf ("--- hash table stats ---\n");
  printf ("buckets: %d \n", table->size);
  printf ("num: %d \n", table->num);
  printf ("------------------------\n");
}

/* ------------------------------------------- */
int main () {
  int i;
  HASH_TABLE *table;
  static char *key[DATA_SIZE] = {
    "alpha", "bravo", "charlie", "delta",
    "echo", "foxtrot", "golf", "hotel",
    "india", "juliet", "kilo", "lima",
    "mike", "november", "oscar", "papa",
    "quebec", "romeo", "sierra", "tango",
    "uniform", "victor", "whisky", "x-ray",
    "yankee", "zulu"
  };

  table = malloc (sizeof (HASH_TABLE));
  hash_table_init (table, HASH_TABLE_SIZE);

  for (i = 0; i < DATA_SIZE; i++) {
    hash_table_insert (table, key[i], i);
  }

  hash_table_info (table);
  hash_table_display (table);

  printf ("search 'sierra' -> %d\n", hash_table_search (table, "sierra"));
  printf ("search 'kilo' -> %d\n", hash_table_search (table, "kilo"));
  printf ("search 'ouj' -> %d\n", hash_table_search (table, "ouj"));

  for (i = 0; i < (DATA_SIZE / 2); i++) {
    hash_table_delete (table, key[i]);
  }

  hash_table_display (table);

  hash_table_free (table);

  free (table);

  return 0;
}
