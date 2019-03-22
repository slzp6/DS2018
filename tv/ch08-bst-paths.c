/* code: ch08-bst-paths.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 2048

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
void print_buffer (int buf[], int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf ("%d", buf[i]);
    if (i != len - 1) {
      printf (" -> ");
    }
  }
  printf ("\n");
}


/* ------------------------------------------ */
void root_to_leaf (NODE_TYPE * node, int path[], int length) {
  if (node == NULL)
    return;

  path[length] = node->data;
  length++;

  if ((node->left == NULL) && (node->right == NULL)) {
    print_buffer (path, length);
  }
  else {
    root_to_leaf (node->left, path, length);
    root_to_leaf (node->right, path, length);
  }
}


/* ------------------------------------------ */
int main () {
  NODE_TYPE *root;
  int i;
  int array[10] = { 40, 30, 70, 10, 60, 90, 20, 80, 50, 100 };
  int *path;

  path = malloc (sizeof (int) * MAX_BUF);

  root = NULL;
  for (i = 0; i < 10; i++) {
    root = tree_insert (root, array[i]);
  }

  tree_display (root, 0);
  printf ("\n\n");

  printf ("--- root-to-leaf path(s) ---\n");
  root_to_leaf (root, path, 0);

  free (path);
  return 0;
}
