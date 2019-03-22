/* code: ch04-list.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};
typedef struct node NODE_TYPE;

/* ------------------------------------------- */
void linked_list_print (NODE_TYPE * node) {
  while (NULL != node) {
    printf ("%d ", node->data);
    node = node->next;
  }
  printf ("\n");
}

/* ------------------------------------------- */
int main () {
  NODE_TYPE *head;
  head = malloc (sizeof (NODE_TYPE));
  head->data = 300;
  head->next = malloc (sizeof (NODE_TYPE));
  head->next->data = 400;
  head->next->next = malloc (sizeof (NODE_TYPE));
  head->next->next->data = 500;
  head->next->next->next = malloc (sizeof (NODE_TYPE));
  head->next->next->next->data = 600;
  head->next->next->next->next = NULL;
  linked_list_print (head);
  return 0;
}
