/* code: ch03-queue-rand-b.c   (v1.18.00) */
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
void queue_print (int q[], int front, int rear) {
  int i;

  printf ("    [ ");
  for (i = front + 1; i < rear + 1; i++) {
    printf ("%d ", q[i]);
  }
  printf ("]");
}


/* ------------------------------------------- */
int main () {
  int *queue;
  int front, rear, data;
  int i, stat;

  queue = malloc (sizeof (int) * MAX);

  queue_init (&front, &rear);

  for (i = 0; i < 20; i++) {
    data = rand () % 1000;
    printf ("data: %3d  ", data);
    if (data > 300) {
      printf ("enqueue %3d ", data);
      enqueue (queue, &rear, data);
    }
    else {
      printf ("dequeue ");
      stat = dequeue (queue, &front, rear, &data);
      if (stat == DEQUEUE_SUCCESS) {
	printf ("%3d ", data);
      }
      else {
	printf (" E  ");
      }
    }
    queue_print (queue, front, rear);
    printf ("\n");
  }


  free (queue);

  return 0;
}
