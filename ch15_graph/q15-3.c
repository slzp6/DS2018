/* code: q15-3.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 128

#define TRUE (1)
#define FALSE (0)

#define ENQUEUE_SUCCESS     (1)
#define ENQUEUE_FAILURE    (-1)
#define DEQUEUE_SUCCESS     (2)
#define DEQUEUE_FAILURE    (-2)
#define QUEUE_NOT_EMPTY     (3)
#define QUEUE_EMPTY        (-3)

struct Vertex {
  char label;
  int visited;
};
typedef struct Vertex VERTEX_TYPE;

/* ------------------------------------------- */
void queue_init (int *front, int *rear) {
  *front = -1;
  *rear = -1;
}

/* ------------------------------------------- */
int is_queue_empty (int front, int rear) {
  if (front == rear) {
    return QUEUE_EMPTY;
  }
  else {
    return QUEUE_NOT_EMPTY;
  }
}

/* ------------------------------------------- */
void queue_print (int q[], int front, int rear) {
  int i;

  printf ("QUEUE[ ");
  for (i = front + 1; i <= rear; i++) {
    printf ("%c", q[i] + 'a');
  }
  printf (" ]\n");
}

/* ------------------------------------------- */
int enqueue (int q[], int *rear, int data) {
  if (*rear < MAX - 1) {
    *rear = *rear + 1;
    q[*rear] = data;
    return ENQUEUE_SUCCESS;
  }
  else {
    return ENQUEUE_FAILURE;
  }
}

/* ------------------------------------------- */
int dequeue (int q[], int *front, int rear, int *data) {
  if (*front == rear) {
    return DEQUEUE_FAILURE;
  }
  *front = *front + 1;
  *data = q[*front];
  return DEQUEUE_SUCCESS;
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
void breadth_first_search (int **adj_matrix,
			   VERTEX_TYPE * vert_list[MAX], int vert_num) {
  int i;
  int queue[MAX];
  int front, rear, data;
  int unvisited;

  data = 0;
  queue_init (&front, &rear);

  vert_list[0]->visited = TRUE;
  g_print_vertex (0, vert_list);

  enqueue (queue, &rear, 0);
  printf ("enqueue (%c) ", data + 'a');
  queue_print (queue, front, rear);

  while (QUEUE_NOT_EMPTY == is_queue_empty (front, rear)) {
    dequeue (queue, &front, rear, &data);
    printf ("dequeue (%c) ", data + 'a');
    queue_print (queue, front, rear);

    while ((unvisited =
	    g_vertex_unvisited (adj_matrix, data, vert_list,
				vert_num)) != -1) {
      vert_list[unvisited]->visited = TRUE;

      g_print_vertex (unvisited, vert_list);

      enqueue (queue, &rear, unvisited);
      printf ("enqueue (%c) ", unvisited + 'a');
      queue_print (queue, front, rear);
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
  printf ("Breadth-First Search (BFS) \n");

  breadth_first_search (adj_matrix, vert_list, vert_num);

  m2d_deallocate (adj_matrix, MAX);
  printf ("\n");

  return 0;
}
