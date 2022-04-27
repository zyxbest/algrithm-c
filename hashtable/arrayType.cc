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
#define MAX_TABLE_SIZE 1000000
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

ElementType nextPrime(int size) {
  int p = (size % 2) ? size + 2 : size + 1;
  size_t i;
  while (p < MAX_TABLE_SIZE) {
    for (i = (int)sqrt(p); i > 2; i--) {
      if (!(p % i)) { //  不是素数
        break;
      }
    }
    if (i == 2) { // 是素数
      break;
    }

    p += 2;
  }
  return p;
}

HashTable createHashTable(int size) {
  HashTable h = (HashTable)malloc(sizeof(HashTableElement));
  h->size = nextPrime(size);
  h->cells = (Cell)malloc(h->size * sizeof(HashEntry));

  for (size_t i = 0; i < h->size; i++) {
    h->cells[i].info = Empty;
    h->cells[i].data = 0;
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
      newPos = curPos + pow((index + 1) / 2, 2);
      while (newPos > h->size) {
        newPos -= h->size;
      }

    } else { // 冲突次数为奇数
      newPos = curPos - pow(index / 2, 2);
      while (newPos < 0) {
        newPos += h->size;
      }
    }
  }
  return newPos;
}

void insert(HashTable h, ElementType key, int i) {
  Position pos = i;
  pos = find(h, key);
  if (pos != Legitimate) {
    h->cells[pos].info = Legitimate;
    h->cells[pos].data = key;
  }
}

void testNextPrime() {
  printf("nextPrime %d\n", nextPrime(19));
  assert(nextPrime(2) == 5);
}

void outPut(HashTable h) {
  for (size_t i = 0; i < h->size; i++) {
    if (h->cells[i].data) {
      cout << i << " : " << h->cells[i].data << endl;
    }
  }
}

void testCreateTable() {
  HashTable h = createHashTable(10);
  assert(h->size == 11);
  assert(h->cells[0].info == Empty);
  int N;
  cin >> N;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    insert(h, temp, i);
  }
  outPut(h);
}

void test() {
  testNextPrime();
  testCreateTable();
}
int main(int argc, char const *argv[]) {

  test();
  return 0;
}
