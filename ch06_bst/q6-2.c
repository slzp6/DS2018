/* code: q6-2.c   (v1.18.00) */
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
int tree_size (NODE_TYPE * node) {
  int s_left, s_right;

  if (node == NULL) {
    return 0;
  }

  s_left = tree_size (node->left);
  s_right = tree_size (node->right);

  return (s_left + s_right + 1);

}

/* ------------------------------------------ */
int main () {
  NODE_TYPE *root;
  int i;
  int array[10] = { 25, 6, 49, 2, 28, 65, 51, 66, 78, 68 };


  root = NULL;
  for (i = 0; i < 10; i++) {
    root = tree_insert (root, array[i]);
  }

  tree_display (root, 0);
  printf ("\n\n");

  printf ("The number of nodes in a BST: %d\n", tree_size (root));

  return 0;
}
