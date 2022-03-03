#if !defined(Queue_H)
#define Queue_H

#define MAXSIZE 4
typedef struct Queue {
  int data[MAXSIZE];
  int front;
  int rear;
} Queue;

// test
void testInitQueue();
#endif // Queue_H
