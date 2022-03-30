#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
typedef int Vertex, Weight;
typedef char DataType;

typedef struct {
  Vertex v1, v2;
  Weight weight;
} ENode, *Edge;

typedef struct {
  Vertex data;
  Weight weight;
  struct AdjNode *next;
} AdjNode, *PtrToAdjNode;

typedef struct {
  PtrToAdjNode firstNode;
  DataType data;
} VNode, AdjList[MaxVertexNum];

typedef struct {
  int nv, ne;
  AdjList G;
} GNode, *LGraph;

LGraph buildGraph(int vertexNum) {
  Vertex nv;
  LGraph g = (LGraph)malloc(sizeof(GNode));
  g->nv = vertexNum;
  g->ne = 0;
  // 初始化表头指针
  for (size_t i = 0; i < vertexNum; i++) {
    g->G[i].firstNode = NULL;
  }
  return g;
}

void insertEdge(LGraph g, Edge edge) {
  int to = edge->v2;
  PtrToAdjNode node = (PtrToAdjNode)malloc(sizeof(AdjNode));
  node->next = NULL;
  node->weight = edge->weight;
  if (g->G[to].firstNode) {
    g->G[to].firstNode->next = node;
  } else {
    g->G[to].firstNode = node;
  }
}

void testBuild() {
  LGraph g = buildGraph(3);
  assert(g->G[2].firstNode == NULL);
}

int main(int argc, char const *argv[]) {
  testBuild();
  return 0;
}
