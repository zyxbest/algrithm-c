#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 65535          // 无穷
#define MaxVertexNum 10         // 最大顶点数
typedef int WeightType, Vertex; // 点和边的权值设为int类型
typedef char DataType;          // 顶点存储的数据设为char类型
typedef struct GNode {
  int Nv;                                   // 顶点个数
  int Ne;                                   // 边的个数
  WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
  DataType Data[MaxVertexNum];              // 顶点存储的数据
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
      graph->G[v][w] = INFINITY; // 初始化为都不连通
    }
  }

  return graph;
}

void insertEdge(MGraph g, Edge e) {
  // 有向图
  g->G[e->v1][e->v2] = e->weight;
  // 无向图
  g->G[e->v2][e->v1] = e->weight;
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

int G[10][10], nv, ne;
MGraph buildGraphQuick() {
  int i, j, v1, v2, w;
  scanf("%d", &nv);
  for (i = 0; i < nv; i++) {
    for (j = 0; j < nv; j++) {
      G[i][j] = 0;
      G[j][i] = 0;
    }
  }
  scanf("%d", &ne);
  for (i = 0; i < ne; i++) {
    scanf("%d %d %d", &v1, &v2, &w);
    G[v1][v2] = w;
    G[v2][v1] = w;
  }
}

// test
void buildTest(); // buildgraph 测试
void handTest();  // 手动第一次测试

int main(int argc, char const *argv[]) {
  // handTest();
  buildTest();

  return 0;
}

void buildTest() {
  MGraph g = buildGraph();

  // buildGraphQuick();
  assert(G[1][4] == 3);
  //   assert(g->Nv == 8);
  //   assert(g->G[3][6] == 1);
}

void handTest() {
  MGraph g = createGraph(8);
  assert(g->Ne == 0);
  assert(g->Nv == 8);
  assert(g->G[0][0] == 0);

  Edge e = (Edge)malloc(sizeof(ENode));
  e->v1 = 1;
  e->v2 = 3;
  e->weight = 10;
  insertEdge(g, e);
  assert(g->G[e->v1][e->v2] == 1);
}