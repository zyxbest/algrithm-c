#include <stdio.h>
#define MaxSize 10
/*
非动态数组
*/
typedef struct {
  int data[MaxSize];
  int length;
} SqList;

void initList(SqList *L) {
  // for (int i = 0; i < MaxSize; i++)
  // {
  //     L->data[i] = 0;
  // }
  L->length = 0;
}

int main(int argc, char const *argv[]) {
  SqList L;
  initList(&L);
  for (int i = 0; i < MaxSize; i++) {
    printf("%d ", L.data[i]);
  }
  return 0;
}
