#include "code03_LinkedStack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
LStack createStack() {
  LStack s = (LNode *)malloc(sizeof(LNode));
  if (s == NULL) {
    printf("no space!\n");
    abort();
  }
  s->next = NULL;
  return s;
}

void destroyStack(LStack s) {
  while (!isEmpty(s)) {
    pop(s);
  }
  free(s);
}

void push(LStack s, int e) {
  LNode *node = (LNode *)malloc(sizeof(LNode));
  node->value = e;

  node->next = s->next;
  s->next = node;
}

int pop(LStack s) {
  if (isEmpty(s)) {
    printf("stack empty\n");
    return 0;
  }

  LNode *first;
  first = s->next;
  int value = first->value;
  //   移除第一个
  s->next = first->next;

  free(first);
  return value;
}

int getTop(LStack s) {
  if (isEmpty(s)) {
    printf("stack empty\n");
    return 0;
  }
  return s->next->value;
}

int isEmpty(LStack s) { return s->next == NULL; }
int main(int argc, char const *argv[]) {
  // testCreateStack();
  exampleRegulation();
  return 0;
}

// test

void testCreateStack() {
  LStack s = createStack();
  push(s, 1);
  push(s, 2);
  push(s, 3);
  assert(pop(s) == 3);
  assert(getTop(s) == 2);
  destroyStack(s);
}

enum {
  MINUS,
  MUTIPLE,
};

enum {
  PLUS,
  DIVIDE,
};
void exampleRegulation() {
  LStack s = createStack();
  char str[100];
  // getStr(&str);
  // printf("str[0] is %c %d\n", str[0], (int)str[0]);
  printf("%d %d %d %d %d %d\n", '+', '-', '*', '/', '(', ')');
  // for (int i = 0; i < strlen(str); i++) {
  //   int c = str[i];
  //   if (isdigit((int)c)) {
  //     printf("%c ", c);
  //   }
  // }
}

void getStr(char *str) {
  scanf("%99s", str);
  printf("%s", str);
}

int compare() {}