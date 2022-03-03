#include "c1_LinkedQueue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
LinkedQueue initLinkedQueue() {
  LinkedQueue q = (LinkedQueue)malloc(sizeof(Link));
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(LinkedQueue q) { return q->front == NULL; }

void addQ(LinkedQueue q, ElemType e) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = e;
  node->next = NULL;
  if (!isEmpty(q)) {
    //   跟上队尾
    q->rear->next = node;
  } else {
    //   新节点，对头也指向该节点
    q->front = node;
  }
  q->rear = node;
}

ElemType delQ(LinkedQueue q) {
  if (isEmpty(q)) {
    printf("del failed, queue is empty!\n ");
    exit(1);
  }

  //   队列只有一个元素
  Node *temp = q->front;
  ElemType e = temp->value;
  if (q->front == q->rear) {
    q->front = q->rear = NULL;
  } else {
    q->front = temp->next;
  }
  free(temp);
  return e;
}

int main(int argc, char const *argv[]) {
  testDelEmptyQ();
  return 0;
}

void testDelEmptyQ() {

  LinkedQueue q = initLinkedQueue(q);
  addQ(q, 1);
  assert(delQ(q) == 1);
  delQ(q);
}
