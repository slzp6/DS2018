/* code: q15-2.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 128

#define TRUE (1)
#define FALSE (0)

#define PUSH_SUCCESS    (1)
#define PUSH_FAILURE   (-1)
#define POP_SUCCESS     (2)
#define POP_FAILURE    (-2)
#define PEEK_SUCCESS     (3)
#define PEEK_FAILURE    (-3)
#define STACK_NOT_EMPTY (4)
#define STACK_EMPTY     (-4)

struct Vertex {
  char label;
  int visited;
};
typedef struct Vertex VERTEX_TYPE;

/* ------------------------------------------- */
void stack_init (int *top) {
  *top = 0;
}

/* ------------------------------------------- */
void display (int stack[], int top) {
  int i;
  printf ("STACK(%d): ", top);
  for (i = 0; i < top; i++) {
    printf ("%d ", stack[i]);
  }
  printf ("\n");
}

/* ------------------------------------------- */
int push (int stack[], int *top, int data) {
  if (*top >= MAX) {
    /* stack overflow */
    return PUSH_FAILURE;
  }
  else {
    stack[*top] = data;
    (*top)++;
    return PUSH_SUCCESS;
  }
}

/* ------------------------------------------- */
int pop (int stack[], int *top, int *data) {
  if ((*top) > 0) {
    *data = stack[(*top) - 1];
    (*top)--;
    return POP_SUCCESS;
  }
  else {
    /* stack empty */
    return POP_FAILURE;
  }
}

/* ------------------------------------------- */
int peek (int stack[], int top, int *data) {
  if (top > 0) {
    *data = stack[top - 1];
    return PEEK_SUCCESS;
  }
  else {
    /* stack empty */
    return PEEK_FAILURE;
  }
}

/* ------------------------------------------- */
int is_stack_empty (int stack[], int top) {
  if (top > 0) {
    return STACK_NOT_EMPTY;
  }
  else {
    return STACK_EMPTY;
  }
}

/* ------------------------------------------- */
void stack_print (int stack[], int top) {
  int i;

  printf ("STACK[ ");
  for (i = 0; i < top; i++) {
    printf ("%c", stack[i] + 'a');
  }
  printf (" ]\n");
}



/* ------------------------------------------- */
int **m2d_allocate (int rows, int columns) {
  int **array;
  int i;
  array = malloc (rows * sizeof (int *));
  for (i = 0; i < rows; i++) {
    array[i] = malloc (columns * sizeof (int));
  }
  return array;
}

/* ------------------------------------------- */
void m2d_deallocate (int **array, int rows) {
  int i;
  for (i = 0; i < rows; i++) {
    free (array[i]);
  }
  free (array);
}

/* ------------------------------------------- */
void g_matrix_init (int **adj_matrix, int max_i, int max_j) {
  int i, j;
  for (i = 0; i < max_i; i++) {
    for (j = 0; j < max_j; j++) {
      adj_matrix[i][j] = 0;
    }
  }
}

/* ------------------------------------------- */
void g_matrix_print (int **adj_matrix, int max_i, int max_j) {
  int i, j;
  printf ("  ");
  for (i = 0; i < max_i; i++) {
    printf ("%c", 'a' + i);
  }
  printf ("\n");
  for (i = 0; i < max_i; i++) {
    printf ("%c ", 'a' + i);
    for (j = 0; j < max_j; j++) {
      printf ("%d", adj_matrix[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}

/* ------------------------------------------- */
int g_add_vertex (int **adj_matrix, VERTEX_TYPE * vert_list[MAX],
		  int vert_num, char label) {
  VERTEX_TYPE *vertex;

  vertex = malloc (sizeof (struct Vertex));
  vertex->label = label;
  vertex->visited = FALSE;
  vert_list[vert_num++] = vertex;

  return vert_num;
}

/* ------------------------------------------- */
void g_add_edge (int **adj_matrix, char label_start, char label_end) {
  int start, end;
  start = label_start - 'a';
  end = label_end - 'a';
  adj_matrix[start][end] = 1;
  adj_matrix[end][start] = 1;
}

/* ------------------------------------------- */
void g_print_vertex (int vert_index, VERTEX_TYPE * vert_list[MAX]) {
  printf ("'%c'\n", vert_list[vert_index]->label);
}

/* ------------------------------------------- */
int g_vertex_unvisited (int **adj_matrix, int vert_index,
			VERTEX_TYPE * vert_list[MAX], int vert_num) {
  int i;
  for (i = 0; i < vert_num; i++) {
    if ((adj_matrix[vert_index][i] == 1)
	&& (vert_list[i]->visited == FALSE)) {
      return i;
    }
  }
  return -1;
}

/* ------------------------------------------- */
void depth_first_search (int **adj_matrix,
			 VERTEX_TYPE * vert_list[MAX], int vert_num) {
  int i;
  int stack[MAX];
  int top, data;
  int unvisited;

  data = 0;
  stack_init (&top);
  vert_list[0]->visited = TRUE;
  g_print_vertex (0, vert_list);
  push (stack, &top, 0);
  printf ("push (%c) ", data + 'a');
  stack_print (stack, top);

  while (STACK_NOT_EMPTY == is_stack_empty (stack, top)) {
    peek (stack, top, &data);
    unvisited = g_vertex_unvisited (adj_matrix, data, vert_list, vert_num);
    if (unvisited == -1) {
      pop (stack, &top, &data);
      printf ("pop  (%c) ", data + 'a');
      stack_print (stack, top);
    }
    else {
      vert_list[unvisited]->visited = TRUE;
      g_print_vertex (unvisited, vert_list);
      push (stack, &top, unvisited);
      printf ("push (%c) ", unvisited + 'a');
      stack_print (stack, top);
    }
  }

  for (i = 0; i < vert_num; i++) {
    vert_list[i]->visited = FALSE;
  }
}

/* ------------------------------------------- */
int main () {
  int **adj_matrix;
  VERTEX_TYPE *vert_list[MAX];
  int vert_num;

  vert_num = 0;
  adj_matrix = m2d_allocate (MAX, MAX);
  g_matrix_init (adj_matrix, MAX, MAX);

  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'a');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'b');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'c');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'd');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'e');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'f');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'g');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'h');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'i');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'j');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'k');
  vert_num = g_add_vertex (adj_matrix, vert_list, vert_num, 'l');

  g_add_edge (adj_matrix, 'a', 'b');
  g_add_edge (adj_matrix, 'a', 'c');
  g_add_edge (adj_matrix, 'b', 'd');
  g_add_edge (adj_matrix, 'b', 'e');
  g_add_edge (adj_matrix, 'd', 'f');
  g_add_edge (adj_matrix, 'e', 'g');
  g_add_edge (adj_matrix, 'e', 'h');
  g_add_edge (adj_matrix, 'g', 'i');
  g_add_edge (adj_matrix, 'g', 'j');
  g_add_edge (adj_matrix, 'h', 'k');
  g_add_edge (adj_matrix, 'i', 'l');
  g_add_edge (adj_matrix, 'j', 'l');

  g_matrix_print (adj_matrix, vert_num, vert_num);
  printf ("Depth-First Search (DFS) \n");

  depth_first_search (adj_matrix, vert_list, vert_num);

  m2d_deallocate (adj_matrix, MAX);
  printf ("\n");

  return 0;
}
