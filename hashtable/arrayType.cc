/*
define

create
insert
find
*/

#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef int ElementType, Position;
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry {
  ElementType data;
  EntryType info;
} HashEntry, *Cell;

typedef struct HashTableElement {
  int size;
  Cell cells;
} HashTableElement, *HashTable;

HashTable createHashTable(int size) {
  HashTable h = (HashTable)malloc(sizeof(HashTableElement));
  h->size = size;
  h->cells = (Cell)malloc(size * sizeof(HashEntry));

  for (size_t i = 0; i < size; i++) {
    h->cells[i].info = Empty;
  }
  return h;
}

ElementType Hash(ElementType key, ElementType size) { return key % size; }

Position find(HashTable h, ElementType key) {
  Position curPos, newPos;
  curPos = newPos = Hash(key, h->size);
  int index = 0;

  while (h->cells[newPos].info != Empty && h->cells[newPos].data != key) {
    if (++index % 2) { // 冲突次数为偶数
      newPos = curPos + sqrt((index + 1) / 2);
      while (newPos > h->size) {
        newPos -= h->size;
      }

    } else { // 冲突次数为奇数
      newPos = curPos - sqrt(index / 2);
      while (newPos < 0) {
        newPos += h->size;
      }
    }
  }
  return newPos;
}

void insert(HashTable h, ElementType key) {
  Position pos = find(h, key);
  if (pos != Legitimate) {
    h->cells[pos].info = Legitimate;
    h->cells[pos].data = key;
  }
}

int main(int argc, char const *argv[]) {
  HashTable h = createHashTable(10);
  assert(h->size == 10);
  assert(h->cells[0].info == Empty);

  int N;
  cin >> N;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    insert(h, temp, i);
  }
  return 0;
}
