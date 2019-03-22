/* code: ch04-list-ins-tail-1.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define NOT_FOUND (-1)
#define DATA_SIZE 100000000

struct node {
  int data;
  struct node *next;
};
typedef struct node NODE_TYPE;

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
  clock_t t_start, t_end;

  head = NULL;

  printf ("DATA_SIZE: %d\n", DATA_SIZE);

  t_start = clock ();
  for (i = 0; i < DATA_SIZE; i++) {
    data1 = (int) rand () % 100;
    linked_list_insert_head (&head, data1);
  }
  t_end = clock ();
  printf ("insert(head): %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);
  linked_list_print_10 (head);
  printf ("\n");

  t_start = clock ();
  linked_list_insert_tail (&head, 100);

  t_end = clock ();
  printf ("insert(tail): %.3lf sec.\n",
	  (double) (t_end - t_start) / (double) CLOCKS_PER_SEC);


  return 0;
}
