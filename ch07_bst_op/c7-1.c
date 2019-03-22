/* code: c7-1.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

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
      printf ("__");
    }
    printf ("%d", node->data);
    tree_display (node->left, level + 1);
  }
}


/* ------------------------------------------ */
NODE_TYPE *tree_find (NODE_TYPE * node, int data) {
  if (node == NULL) {
    return NULL;
  }
  if (data < (node->data)) {
    return tree_find (node->left, data);
  }
  if (data > (node->data)) {
    return tree_find (node->right, data);
  }
  return node;
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
int main () {
  NODE_TYPE *root;
  NODE_TYPE *node;
  int i, v;
  int data[] = { 40, 30, 70, 10, 60, 90, 20, 80 };
  root = NULL;

  for (i = 0; i < 8; i++) {
    printf ("%2d ", data[i]);
    root = tree_insert (root, data[i]);
  }
  printf ("\n\n*** binary search tree ***");
  tree_display (root, 0);

  v = 80;
  printf ("\n\n*** searching for a node [%d] ***\n", v);
  node = tree_find (root, v);
  if (node != NULL) {
    printf ("node [%d] found!", node->data);
  }
  printf ("\n");

  return 0;
}
