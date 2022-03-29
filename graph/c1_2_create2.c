#include <stdio.h>
#include <stdlib.h>
const int MaxVertexNum = 10;
typedef int Vertex, Weight;
typedef char DataType;

typedef struct {
  Vertex v1, v2;
  Weight weight;
} ENode, *Edge;

typedef struct {
  Vertex data;
  Weight weight;
  PtrToAdjNode next;
} AdjNode, *PtrToAdjNode;

typedef struct {
  PtrToAdjNode firstNode;
  DataType data;
} VNode, AdjList[MaxVertexNum];

int main(int argc, char const *argv[]) { return 0; }
