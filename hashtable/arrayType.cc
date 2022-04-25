/*
define

create
insert
find
*/

#include <cassert>
#include <iostream>
using namespace std;
typedef int ElementType;
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

int main(int argc, char const *argv[]) {
  HashTable h = createHashTable(10);
  assert(h->size == 10);
  return 0;
}
