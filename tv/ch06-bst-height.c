/* code: ch06-bst-height.c   (v1.18.00) */
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
int tree_height (NODE_TYPE * node) {
  int h_left, h_right;

  if (node == NULL) {
    return -1;
  }

  h_left = tree_height (node->left);
  h_right = tree_height (node->right);

  if (h_left > h_right) {
    return h_left + 1;
  }
  else {
    return h_right + 1;
  }
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

  printf ("The height of a BST: %d\n", tree_height (root));

  return 0;
}
