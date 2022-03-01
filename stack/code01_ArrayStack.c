
#include "code01_ArrayStack.h"

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  SqStack s;
  initStack(&s);
  push(s, 1);
  push(s, 2);
  push(s, 3);

  int top = 0;
  if (getTop(s, &top)) {
    printf("top is %d\n", top);
  }

  destroyStack(s);
  int x = 0;

  while (!isEmpty(s)) {
    if (pop(s, &x)) {
      printf("pop %d\n", x);
    }
  }

  return 0;
}

void initStack(SqStack *s) {
  *s = (SqStack *)malloc(sizeof(SqStack));
  // s->data = (int *)malloc(sizeof(int) * MAXSIZE);
  (*s)->top = -1;
}

void destroyStack(SqStack *s) {
  free(s->data);
  free(s);
  // s->top = 0;
}

void push(SqStack s, int x) {
  if (isFull(s)) {
    printf("arrive at max index");
    return;
  }

  s->data[++s->top] = x;
  return 1;
}

int isEmpty(SqStack s) { return s->top == -1; }

int isFull(SqStack s) { return s->top == MAXSIZE; }

int pop(SqStack s, int *x) {
  if (isEmpty(s)) {
    printf("stack empty\n");
    return 0;
  }
  *x = s->data[s->top--];
  return 1;
}

int getTop(SqStack s, int *x) {
  if (isEmpty(s)) {
    return 0;
  }
  *x = s->data[s->top];
  return 1;
}