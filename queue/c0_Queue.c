#include "c0_Queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
Queue *initQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = 0;
  queue->rear = 0;
  return queue;
}

void addQ(Queue *queue, int e) {
  if ((queue->rear + 1) % MAXSIZE == queue->front) {
    printf("full \n");
    exit(1);
  }

  queue->rear = (queue->rear + 1) % MAXSIZE;
  queue->data[queue->rear] = e;
}

int delQ(Queue *queue) {
  if (queue->rear == queue->front) {
    printf("empty \n");
    exit(1);
  }

  queue->front = (queue->front + 1) % MAXSIZE;
  int e = queue->data[queue->front];
  return e;
}
int main(int argc, char const *argv[]) {

  testInitQueue();
  return 0;
}

// test

void testInitQueue() {

  Queue *queue = initQueue();
  assert(queue->front == queue->rear);
  addQ(queue, 2);
  addQ(queue, 1);
  addQ(queue, 1);
  assert(delQ(queue) == 2);
  addQ(queue, 1);
  addQ(queue, 1);
}
