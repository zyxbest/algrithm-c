#include "code02_DoubleStack.h"

#include <stdio.h>
#include <stdlib.h>

void push(DStack stack, int e, int tag) {
  if (stack->top2 - stack->top1 == 1) {
    printf("使用空间已满\n");
    return;
  }

  if (tag == 1) {
    stack->data[++stack->top1] = e;
  } else {
    stack->data[--stack->top2] = e;
  }
}

/**
 * @brief 初始化
 *
 * @param stack
 */
void initDStack(DStack *stack) {
  *stack = (DNode *)malloc(sizeof(DNode));
  (*stack)->top1 = -1;
  (*stack)->top2 = MAXSIZE;
}

void destroyDStack(DStack *stack) { free(*stack); }

int pop(DStack s, int tag) {
  if (tag == 1) {
    if (s->top1 == -1) {
      printf("没数据了\n");
      abort();
    } else {
      return s->data[s->top1--];
    }
  } else {
    if (s->top2 == MAXSIZE) {
      printf("没数据了\n");
      abort();
    } else {
      return s->data[s->top2++];
    }
  }
}

int main(int argc, char const *argv[]) {
  testDestroy();
  testPush();
  testPop();
  return 0;
}

// test

void testDestroy() {
  DStack s;
  initDStack(&s);
  push(s, 1, 1);
  push(s, 2, 2);
  destroyDStack(&s);
}

void testPop() {
  DStack s;
  initDStack(&s);
  push(s, 1, 1);
  push(s, 2, 2);
  assert(pop(s, 1) == 1);
  assert(pop(s, 2) == 2);
  pop(s, 1);
  pop(s, 2);
}

void testPush() {
  DStack s;
  initDStack(&s);
  push(s, 1, 1);
  push(s, 1, 1);
  push(s, 1, 1);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
  push(s, 2, 2);
}