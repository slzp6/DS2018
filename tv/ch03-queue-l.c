/* code: ch03-queue-l.c   (v1.18.00) */
#include<stdio.h>
#include<stdlib.h>

#define DATA_SIZE    100000000
#define MAX          100000000

#define ENQUEUE_SUCCESS     1
#define ENQUEUE_FAILURE    -1
#define DEQUEUE_SUCCESS     2
#define DEQUEUE_FAILURE    -2

/* ------------------------------------------- */
void queue_init (int *front, int *rear) {
  *front = -1;
  *rear = -1;
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
int main () {
  int *queue;
  int front, rear, data;
  int i, stat;

  queue = malloc (sizeof (int) * MAX);

  queue_init (&front, &rear);

  printf ("data size: %d\n\n", DATA_SIZE);

  printf ("enqueue:\n");
  for (i = 0; i < DATA_SIZE; i++) {
    data = rand () % 1000;
    if (i < 10)
      printf ("%3d ", data);
    enqueue (queue, &rear, data);
  }
  printf ("\n");


  printf ("dequeue:\n");
  while ((10 - 1) - front) {
    stat = dequeue (queue, &front, rear, &data);
    if (stat == DEQUEUE_SUCCESS) {
      printf ("%d ", data);
    }
    else {
      printf ("QUEUE is empty\n");
    }
  }
  printf ("\n");

  free (queue);

  return 0;
}
