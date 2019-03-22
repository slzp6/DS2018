/* code: ch04-list-del-head.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>
#define NOT_FOUND (-1)
#define DATA_SIZE 100000
struct node {
  int data;
  struct node *next;
};
typedef struct node NODE_TYPE;

/* ------------------------------------------- */
void linked_list_print_10 (NODE_TYPE * head) {
  int i;
  i = 0;
  printf ("Linked_list [ ");
  while (NULL != head && i < 10) {
    printf ("%02d ", head->data);
    head = head->next;
    i++;
  }
  printf (" ... ]\n");
}


/* ------------------------------------------- */
void linked_list_insert_head (NODE_TYPE ** head, int data) {
  NODE_TYPE *new_node;
  new_node = malloc (sizeof (NODE_TYPE));
  new_node->data = data;
  if (*head == NULL) {
    new_node->next = NULL;
    *head = new_node;
  }
  else {
    new_node->next = *head;
    *head = new_node;
  }
}

/* ------------------------------------------- */
int linked_list_delete_head (NODE_TYPE ** head) {
  int data;
  NODE_TYPE *temp;
  if (*head == NULL) {
    return NOT_FOUND;
  }
  data = (*head)->data;
  temp = (*head);
  *head = (*head)->next;
  free (temp);
  return data;
}


/* ------------------------------------------- */
int main () {
  NODE_TYPE *head;
  int i, data1;

  head = NULL;

  printf ("DATA_SIZE: %d\n", DATA_SIZE);

  printf ("inserting (head): ");
  for (i = 0; i < DATA_SIZE; i++) {
    data1 = (int) rand () % 100;
    linked_list_insert_head (&head, data1);
  }
  printf ("done\n");
  fflush (stdout);

  linked_list_print_10 (head);

  printf ("deleting (head): ");
  for (i = 0; i < DATA_SIZE; i++) {
    data1 = linked_list_delete_head (&head);
  }
  printf ("done\n");
  fflush (stdout);


  return 0;
}
