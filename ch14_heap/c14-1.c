/* code: c14-1.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define MAX_PQ_SIZE 128
#define NODE_PARENT(x) ((x - 1) / 2)
#define NODE_LEFT(x) (2 * x + 1)
#define NODE_RIGHT(x) (2 * x + 2)

struct node {
  int priority;
  char data[32];
};
typedef struct node NODE;

struct p_queue {
  int size;
  NODE *elm;
};
typedef struct p_queue P_QUEUE;

/* ------------------------------------------- */
void pq_node_swap (NODE * n1, NODE * n2) {
  NODE node_temp;
  node_temp = *n1;
  *n1 = *n2;
  *n2 = node_temp;
}

/* ------------------------------------------- */
P_QUEUE pq_init (int size) {
  P_QUEUE pq;
  pq.size = 0;
  pq.elm = malloc (size * sizeof (NODE));
  return pq;
}

/* ------------------------------------------- */
void pq_delete_all (P_QUEUE * pq) {
  free (pq->elm);
}

/* ------------------------------------------- */
void pq_display (P_QUEUE * pq) {
  int i;
  for (i = 0; i < pq->size; i++) {
    printf ("heap    (%d) (%s)\n", pq->elm[i].priority, pq->elm[i].data);
  }
}

/* ------------------------------------------- */
void pq_heapify (P_QUEUE * pq, int i) {
  int max;
  max = ((NODE_LEFT (i) < pq->size)
	 && (pq->elm[NODE_LEFT (i)].priority >
	     pq->elm[i].priority)) ? NODE_LEFT (i) : i;

  if ((NODE_RIGHT (i) < pq->size)
      && (pq->elm[NODE_RIGHT (i)].priority > pq->elm[max].priority)) {
    max = NODE_RIGHT (i);
  }
  if (max != i) {
    pq_node_swap (&(pq->elm[i]), &(pq->elm[max]));
    pq_heapify (pq, max);
  }
}

/* ------------------------------------------- */
void pq_enqueue (P_QUEUE * pq, int priority, char *data) {
  NODE node;
  int i;

  node.priority = priority;
  sprintf (node.data, "%s", data);
  printf ("enqueue (%2d)(%s)\n", node.priority, node.data);
  i = (pq->size)++;
  while (i && node.priority > pq->elm[NODE_PARENT (i)].priority) {
    pq->elm[i] = pq->elm[NODE_PARENT (i)];
    i = NODE_PARENT (i);
  }
  pq->elm[i] = node;
}

/* ------------------------------------------- */
void pq_dequeue (P_QUEUE * pq) {
  if (pq->size) {
    printf ("dequeue (%2d)(%s)\n", pq->elm[0].priority, pq->elm[0].data);
    pq->elm[0] = pq->elm[--(pq->size)];
    pq->elm = realloc (pq->elm, pq->size * sizeof (NODE));
    pq_heapify (pq, 0);
  }
  else {
    printf ("priority queue is empty\n");
  }
}

/* ------------------------------------------- */
int main () {
  P_QUEUE pq;
  int i;

  pq = pq_init (MAX_PQ_SIZE);
  pq_enqueue (&pq, 40, "grape");
  pq_enqueue (&pq, 30, "pear");
  pq_enqueue (&pq, 10, "banana");
  pq_enqueue (&pq, 20, "watermelon");
  pq_enqueue (&pq, 50, "apple");
  pq_enqueue (&pq, 60, "lemon");
  pq_display (&pq);
  for (i = 0; i < 7; i++) {
    pq_dequeue (&pq);
  }
  pq_delete_all (&pq);

  return 0;
}
