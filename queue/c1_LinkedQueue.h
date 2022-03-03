#if !defined(Linked_Queue_h)
#define Linked_Queue_h

typedef int ElemType;

typedef struct Node {
  ElemType value;
  struct Node *next;

} Node;

typedef struct LinkedQueue {
  struct Node *front, *rear;
} Link, *LinkedQueue;
// test
void testDelEmptyQ();
#endif // Linked_Queue_h
