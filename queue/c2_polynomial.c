#include <stdio.h>
/**
 * @brief 多项式加法 queue的使用
 *
 */

#include <assert.h>
#include <stdlib.h>

#include "c2_polynomial.h"

int compare(int x, int y) { return x == y ? 0 : x < y ? -1 : 1; }
void append(int c, int e, Polynomial *rear) {
  PolyNode *p = (PolyNode *)malloc(sizeof(PolyNode));
  p->coefficient = c;
  p->exponent = e;
  p->next = NULL;

  (*rear)->next = p;
  *rear = p;
}
PolyNode *polynomial(Polynomial p1, Polynomial p2) {
  Polynomial front = (PolyNode *)malloc(sizeof(PolyNode));
  Polynomial rear = front;
  while (p1 && p2) {
    switch (compare(p1->exponent, p2->exponent)) {
      //   p1较小
    case -1:
      append(p1->coefficient, p1->exponent, &rear);
      p1 = p1->next;
      break;
    case 0:
      int sum = p1->coefficient + p2->coefficient;
      if (sum) {
        append(sum, p1->exponent, &rear);
      }
      p1 = p1->next;
      p2 = p2->next;
      break;
    case 1:
      append(p2->coefficient, p2->exponent, &rear);
      p2 = p2->next;
      break;
    default:
      break;
    }
  }

  for (; p1; p1 = p1->next) {
    append(p1->coefficient, p1->exponent, &rear);
  }
  for (; p2; p2 = p2->next) {
    append(p2->coefficient, p2->exponent, &rear);
  }

  //   清除工作
  /*   PolyNode *temp = front;
    front = front->next;
    free(temp);
    return front; */

  PolyNode *temp = front->next;
  free(front);
  return temp;
}

PolyNode *initQ() {
  PolyNode *p = (PolyNode *)malloc(sizeof(PolyNode));
  p->next = NULL;
  return p;
}

void addQ(PolyNode *p, int c, int e) {
  PolyNode *temp = (PolyNode *)malloc(sizeof(PolyNode));
  temp->coefficient = c;
  temp->exponent = e;

  p->next = temp;
}

int main(int argc, char const *argv[]) {
  testCompare();
  test();
  return 0;
}

void testCompare() {
  assert(compare(3, 6) == -1);
  assert(compare(3, 3) == 0);
  assert(compare(4, 3) == 1);
}

void init(PolyNode **node1, PolyNode **node2) {
  PolyNode *p1 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *temp = p1;

  temp->coefficient = 3;
  temp->exponent = 4;
  temp->next = (PolyNode *)malloc(sizeof(PolyNode));
  temp = temp->next;

  temp->coefficient = 4;
  temp->exponent = 2;
  temp->next = (PolyNode *)malloc(sizeof(PolyNode));
  temp = temp->next;

  temp->coefficient = 1;
  temp->exponent = 0;
  temp->next = NULL;

  PolyNode *p2 = (PolyNode *)malloc(sizeof(PolyNode));
  temp = p2;

  temp->coefficient = 6;
  temp->exponent = 4;
  temp->next = (PolyNode *)malloc(sizeof(PolyNode));
  temp = temp->next;

  temp->coefficient = 4;
  temp->exponent = 3;
  temp->next = (PolyNode *)malloc(sizeof(PolyNode));
  temp = temp->next;

  temp->coefficient = 1;
  temp->exponent = 2;
  temp->next = (PolyNode *)malloc(sizeof(PolyNode));
  temp = temp->next;

  temp->coefficient = 4;
  temp->exponent = 0;
  temp->next = NULL;

  (*node1) = p1;
  (*node2) = p2;
}

void test() {

  // 3x^4 + 4x^2 +1
  // 6x^4 + 4x^3+x^2 +4
  PolyNode *p1, *p2, *temp;
  init(&p1, &p2);

  printf("p1\n");
  printP(p1);
  printf("p2\n");
  printP(p2);
  temp = polynomial(p1, p2);
  printf("p3\n");
  printP(temp);
}

void printP(PolyNode *temp) {
  while (temp) {
    printf("c:%d e:%d\n", temp->coefficient, temp->exponent);
    temp = temp->next;
  }
}