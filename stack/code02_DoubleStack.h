#if !defined(DOUBLE_STACK_H)
#define DOUBLE_STACK_H

#include <assert.h>

#define MAXSIZE 10
typedef struct DNode {
  int data[MAXSIZE];
  int top1;
  int top2;
} DNode, *DStack;

#endif  // DOUBLE_STACK_H
