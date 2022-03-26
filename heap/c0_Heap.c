#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxData 10000 // 哨兵
typedef struct HeapStruct {
  int *elements;
  int size;
  int capacity;
} HeapStruct, *MaxHeap;

int isFull(MaxHeap heap);

// 建堆
MaxHeap createHeap(int maxSize) {

  MaxHeap heap = (MaxHeap)malloc(sizeof(HeapStruct));
  heap->elements = malloc((maxSize + 1) * sizeof(int));
  heap->capacity = maxSize;
  heap->size = 0;
  heap->elements[0] = MaxData;
  return heap;
}

void insert(MaxHeap heap, int v) {
  if (isFull(heap)) {
    printf("heap 已满！\n");
    return;
  }

  int parent = ++heap->size;
  for (; heap->elements[parent / 2] < v; parent /= 2) {
    heap->elements[parent] = heap->elements[parent / 2];
  }
  heap->elements[parent] = v;
}

int deleteMax(MaxHeap heap) {
  int max = heap->elements[1];
  int last = heap->elements[heap->size--];
  heap->elements[1] = last;

  int child;
  int parent;
  for (parent = 1; parent * 2 <= heap->size; parent = child) {
    child = parent * 2;
    if (child != heap->size &&
        heap->elements[child + 1] > heap->elements[child]) {
      child++;
    }

    if (heap->elements[child] <= last) {
      break;
    } else {
      heap->elements[parent] = heap->elements[child];
    }
  }

  heap->elements[parent] = last;
  return max;
}

int isFull(MaxHeap heap) { return heap->size == heap->capacity - 1; }

int main(int argc, char const *argv[]) {
  MaxHeap m = createHeap(10);
  printf("m.elements[0] %d\n", m->elements[0]);

  insert(m, 3);
  insert(m, 15);
  insert(m, 7);
  insert(m, 4);

  assert(deleteMax(m) == 15);
  assert(deleteMax(m) == 7);
  assert(deleteMax(m) == 3);
  assert(deleteMax(m) == 4);
  return 0;
}
