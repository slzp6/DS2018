/* code: ch11-bst-inorder-stack.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE_TYPE;

struct Stack {
  struct Node *t;
  struct Stack *next;
};
typedef struct Stack STACK_TYPE;




/* ------------------------------------------ */
void push (STACK_TYPE ** stack, NODE_TYPE * t) {
  STACK_TYPE *newnode;

  newnode = malloc (sizeof (STACK_TYPE));

  if (newnode == NULL) {
    printf ("ERROR: stack overflow \n");
    exit (-1);
  }

  newnode->t = t;
  newnode->next = *stack;

  *stack = newnode;
}


/* ------------------------------------------ */
int is_stack_empty (STACK_TYPE * top) {
  return (top == NULL) ? 1 : 0;
}


/* ------------------------------------------ */
NODE_TYPE *pop (STACK_TYPE ** stack) {
  NODE_TYPE *node;
  STACK_TYPE *top;

  if (is_stack_empty (*stack)) {
    printf ("ERROR: stack underflow \n");
    exit (-1);
  }
  else {
    top = *stack;
    node = top->t;
    *stack = top->next;
    free (top);
    return node;
  }
}

/* ------------------------------------------ */
void inorder_recursion (NODE_TYPE * node) {
  if (node != NULL) {
    inorder_recursion (node->left);
    printf ("%d ", node->data);
    inorder_recursion (node->right);
  }
}


/* ------------------------------------------ */
void inorder_stack (NODE_TYPE * root) {
  int flag;
  STACK_TYPE *stack;
  NODE_TYPE *node;

  node = root;
  stack = NULL;
  flag = 0;

  while (!flag) {
    if (node != NULL) {
      push (&stack, node);
      node = node->left;
    }
    else {
      if (!is_stack_empty (stack)) {
	node = pop (&stack);
	printf ("%d ", node->data);
	node = node->right;
      }
      else {
	flag = 1;
      }
    }
  }
}



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
  int i;
  int data[] = { 40, 30, 70, 10, 60, 90, 20, 80 };
  root = NULL;

  for (i = 0; i < 8; i++) {
    printf ("%2d ", data[i]);
    root = tree_insert (root, data[i]);
  }
  printf ("\n\n");
  printf ("*** binary search tree ***\n");
  tree_display (root, 0);

  printf ("\n\n*** inorder traversal (recursion) ***\n");
  inorder_recursion (root);

  printf ("\n\n*** inorder traversal (stack) ***\n");
  inorder_stack (root);

  printf ("\n");

  return 0;
}
