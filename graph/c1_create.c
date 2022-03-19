#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10;
typedef int WeightType, Vertex;

typedef struct GNode {
  int Nv;
  int Ne;
  WeightType G[10][10];
} GNode, *PtrGNode, *MGraph;

typedef struct ENode {
  Vertex v1, v2;
  WeightType weight;
} ENode, *PtrENode, *Edge;

MGraph createGraph(int vertexNum) {
  Vertex v, w;
  MGraph graph;

  graph = (MGraph)malloc(sizeof(GNode));
  graph->Nv = vertexNum;
  graph->Ne = 0;

  for (v = 0; v < vertexNum; v++) {
    for (w = 0; w < vertexNum; w++) {
      graph->G[v][w] = 0;
    }
  }

  return graph;
}

void insertEdge(MGraph g, Edge e) {
  // 有向图
  g->G[e->v1][e->v2] = 1;

  // 无向图
  g->G[e->v2][e->v1] = 1;
}

MGraph buildGraph() {
  MGraph graph;
  Edge edge;
  int nv;
  scanf("%d", &nv);
  graph = createGraph(nv);
  scanf("%d", &(graph->Ne));

  if (graph->Ne) {
    for (int i = 0; i < graph->Ne; i++) {
      edge = (Edge)malloc(sizeof(ENode));
      scanf("%d %d %d", &edge->v1, &edge->v2, &edge->weight);
      insertEdge(graph, edge);
    }
  }

  return graph;
}

// test
void buildTest(); // buildgraph 测试
void handTest();  // 手动第一次测试

int main(int argc, char const *argv[]) {
  handTest();
  buildTest();
  return 0;
}

void buildTest() {
  MGraph g = buildGraph();
  //   assert(g->Nv == 8);
  //   assert(g->G[3][6] == 1);
}

void handTest() {
  MGraph g = createGraph(8);
  assert(g->Ne == 0);
  assert(g->Nv == 8);
  assert(g->G[0][0] == 0);

  Edge e = malloc(sizeof(ENode));
  e->v1 = 1;
  e->v2 = 3;
  e->weight = 10;
  insertEdge(g, e);
  assert(g->G[e->v1][e->v2] == 1);
}