#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
/*
非动态数组
*/
typedef struct {
  int *data;
  int maxSize;
  int length;
} SqList;

void initList(SqList *L) {
  // 涉及到指针的话，就需要分配内存空间了
  L->data = (int *)malloc(InitSize * (sizeof(int)));
  L->maxSize = InitSize;
  L->length = 0;
}

/**
 * @brief 扩展数组
 *
 * @param L
 * @param len 新的长度
 */
void increaseSize(SqList *L, int len) {
  int *temp = L->data;
  L->data = (int *)malloc((L->maxSize + len) * sizeof(int));
  for (int i = 0; i < L->length; i++) {
    L->data[i] = temp[i];
  }
  free(temp);
}

/**
 * @brief 在第几个元素插入
 * 为啥不是index，而是位序
 * @param L SqList
 * @param index 位序
 * @param e 元素
 * @return 状态
 */
int insert(SqList *L, int index, int e) {
  // 边缘条件
  if (index < 1 || index > L->length + 1) {
    exit(EXIT_FAILURE);
    return 0;
  }

  L->length++;
  if (L->length > L->maxSize) {
    increaseSize(L, 10);
  }

  for (int i = L->length; i >= index; i--) {
    L->data[i] = L->data[i - 1];
  }

  L->data[index - 1] = e;
  return 1;
}

/**
 * @brief 删除指定位序的元素
 *
 * @param L
 * @param index 位序
 * @param e 删除的元素的地址
 * @return int 删除的结果
 */
int delete (SqList *L, int index, int *e) {
  if (index < 1 || index > L->length + 1) {
    return 0;
  }

  *e = L->data[index - 1];
  for (int i = index; i < L->length; i++) {
    L->data[i - 1] = L->data[i];
  }
  L->length--;
  return 1;
}

// 按位查找
int getElem(SqList *L, int i) {
  if (i < 1 || i > L->length) {
    printf("出错啦");
    exit(EXIT_FAILURE);
  }

  return L->data[i - 1];
}

int getIndex(SqList *L, int e) {
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

int add(SqList *L, int e) { return insert(L, L->length + 1, e); }

void printArr(SqList *L) {
  printf("Arr: ");
  for (int i = 0; i < L->length; i++) {
    printf("%d ", L->data[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  SqList L;
  initList(&L);
  add(&L, 0);
  add(&L, 1);
  add(&L, 2);
  // ...add
  // increaseSize(&L, 10);
  insert(&L, 3, 3);

  printArr(&L);

  int e = -1;
  if (delete (&L, 3, &e)) {
    printf("删除的元素为 %d\n", e);
  } else {
    printf("删除的i位序不合法");
  }

  printArr(&L);

  int index = getIndex(&L, 2);
  printf("2 位序为 %d\n", index);
  return 0;
}
