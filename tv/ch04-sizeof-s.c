/* code: ch04-sizeof-s.c   (v1.18.00) */
#include <stdio.h>

struct Node {
  int data_i;
  struct Node *next;
};
typedef struct Node NODE_TYPE;

int main () {
  NODE_TYPE *node;

  printf ("node   (NODE_TYPE)     %zd byte(s)\n", sizeof (NODE_TYPE));
  printf ("\n");
  printf ("data_i (int)           %zd byte(s)\n", sizeof (node->data_i));
  printf ("next   (struct Node *) %zd byte(s)\n", sizeof (node->next));

  return 0;
}
