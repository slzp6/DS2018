/* code: ch04-sizeof-l.c   (v1.18.00) */
#include <stdio.h>

struct Node {
  int data_i;
  float data_f;
  double data_d;
  char data_c;
  char data_s[32];
  struct Node *next;
};
typedef struct Node NODE_TYPE;

int main () {
  NODE_TYPE *node;

  printf ("node   (NODE_TYPE)     %zd byte(s)\n", sizeof (NODE_TYPE));
  printf ("\n");
  printf ("data_i (int)           %zd byte(s)\n", sizeof (node->data_i));
  printf ("data_f (float)         %zd byte(s)\n", sizeof (node->data_f));
  printf ("data_d (double)        %zd byte(s)\n", sizeof (node->data_d));
  printf ("data_c (char)          %zd byte(s)\n", sizeof (node->data_c));
  printf ("data_s (char s[32])    %zd byte(s)\n", sizeof (node->data_s));
  printf ("next   (struct Node *) %zd byte(s)\n", sizeof (node->next));

  return 0;
}
