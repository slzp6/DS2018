/* code: ch04-list-ins-tail.c   (v1.18.00) */
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
void linked_list_insert_tail (NODE_TYPE ** head, int data) {
  NODE_TYPE *new_node;
  NODE_TYPE *temp;
  new_node = malloc (sizeof (NODE_TYPE));

  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL) {
    *head = new_node;
    temp = new_node;
  }
  else {
    temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}


/* ------------------------------------------- */
int main () {
  NODE_TYPE *head;
  int i, data1;

  head = NULL;

  printf ("DATA_SIZE: %d\n", DATA_SIZE);
  for (i = 0; i < DATA_SIZE; i++) {
    data1 = (int) rand () % 100;
    linked_list_insert_tail (&head, data1);
  }
  linked_list_print_10 (head);

  return 0;
}
