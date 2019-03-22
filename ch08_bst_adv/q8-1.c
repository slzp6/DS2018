/* code: q8-1.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE_TYPE;

/* ------------------------------------------ */
void tree_display (NODE_TYPE * node, int level) {
  int i;

  if (node != NULL) {
    tree_display (node->right, level + 1);

    printf ("\n");
    for (i = 0; i < level; i++) {
      printf ("_");
    }
    printf ("%d", node->data);
    tree_display (node->left, level + 1);
  }
}


/* ------------------------------------------ */
NODE_TYPE *tree_insert (NODE_TYPE * node, int data) {
  if (node == NULL) {
    if (NULL == (node = malloc (sizeof (NODE_TYPE)))) {
      printf ("\nERROR: Can not allocate memory");
      exit (-1);
    }

    node->left = NULL;
    node->right = NULL;
    node->data = data;
  }
  else {
    if (data < node->data) {
      node->left = tree_insert (node->left, data);
    }
    else if (data > node->data) {
      node->right = tree_insert (node->right, data);
    }
  }

  return node;
}


/* ------------------------------------------ */
int tree_identical (NODE_TYPE * a, NODE_TYPE * b) {
  int stat;

  if ((a == NULL) && (b == NULL)) {
    return TRUE;
  }
  else if ((a != NULL) && (b != NULL)) {
    stat = (a->data == b->data) &&
      tree_identical (a->left, b->left) &&
      tree_identical (a->right, b->right);
    return stat;
  }
  else {
    return FALSE;
  }
}

/* ------------------------------------------ */
int main () {
  NODE_TYPE *root_x;
  NODE_TYPE *root_y;
  int i, s;
  int array_x[5] = { 40, 30, 20, 10, 50 };
  int array_y[5] = { 40, 30, 10, 20, 50 };

  root_x = NULL;
  root_y = NULL;
  for (i = 0; i < 5; i++) {
    root_x = tree_insert (root_x, array_x[i]);
    root_y = tree_insert (root_y, array_y[i]);
  }

  tree_display (root_x, 0);
  printf ("\n\n");
  tree_display (root_y, 0);
  printf ("\n\n");

  s = tree_identical (root_x, root_y);
  if (s == TRUE) {
    printf ("identical\n");
  }
  else if (s == FALSE) {
    printf ("different\n");
  }
  return 0;
}
