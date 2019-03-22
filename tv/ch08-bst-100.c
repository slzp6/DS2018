/* code: ch08-bst-100.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE_TYPE;

/* ------------------------------------------ */
int int_compare (const void *va, const void *vb) {
  int a, b;
  a = *(int *) va;
  b = *(int *) vb;
  if (a < b) {
    return (-1);
  }
  else if (a > b) {
    return (1);
  }
  else {
    return (0);
  }
}

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
void tree_delete (NODE_TYPE * node) {
  if (node == NULL)
    return;

  tree_delete (node->left);
  tree_delete (node->right);
  free (node);
}

/* ------------------------------------------ */
void tree_delete_wrapper (NODE_TYPE ** node) {
  tree_delete (*node);
  *node = NULL;
}

/* ------------------------------------------ */
int main () {
  NODE_TYPE *root;
  int i, v;

  root = NULL;
  for (i = 0; i < 100; i++) {
    v = rand () % 1000;
    root = tree_insert (root, v);
  }

  tree_display (root, 0);
  printf ("\n\n");

  /* tree_delete_wrapper (&root); */

  return 0;
}
