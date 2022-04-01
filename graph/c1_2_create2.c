#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* 邻接表图 */
#define MaxVertexNum 10     // 最大定点数
typedef int Vertex, Weight; // 顶点下标和权值
typedef char DataType;      // 顶点的数据类型

typedef struct {
  Vertex v1, v2; // 有向边<v1,v2>
  Weight weight; // 权值
} ENode, *Edge;

typedef struct AdjNode *PtrToAdjNode;
typedef struct AdjNode {
  Vertex adjV; // 邻接点下标
  Weight weight;
  PtrToAdjNode next;
} AdjNode;

typedef struct {
  PtrToAdjNode firstEdge;
  DataType data;
} VNode, AdjList[MaxVertexNum];

typedef struct {
  int nv, ne;
  AdjList G;
} GNode, *LGraph;

LGraph createGraph(int vertexNum) {
  Vertex nv;
  LGraph g = (LGraph)malloc(sizeof(GNode));
  g->nv = vertexNum;
  g->ne = 0;
  // 初始化表头指针
  for (size_t i = 0; i < vertexNum; i++) {
    g->G[i].firstEdge = NULL;
  }
  return g;
}

void insertEdge(LGraph g, Edge edge) {
  PtrToAdjNode node = (PtrToAdjNode)malloc(sizeof(AdjNode));
  node->weight = edge->weight;
  node->adjV = edge->v2;

  /* 将v2插入v1 */
  node->next = g->G[edge->v1].firstEdge;
  g->G[edge->v1].firstEdge = node;

  /* 无向图还需要将v1插入v2 */

  node = (PtrToAdjNode)malloc(sizeof(AdjNode));
  node->weight = edge->weight;
  node->adjV = edge->v1;

  node->next = g->G[edge->v2].firstEdge;
  g->G[edge->v2].firstEdge = node;
}

LGraph buildGraph() {
  int nv, ne;
  scanf("%d", &nv);

  LGraph g = createGraph(nv);

  scanf("%d", &ne); //读入边数

  Edge e = (Edge)malloc(sizeof(ENode));
  for (size_t i = 0; i < ne; i++) {
    scanf("%d %d %d", &e->v1, &e->v2, &e->weight);
    insertEdge(g, e);
  }

  free(e);
  return g;
}

void testBuild() {
  LGraph g = buildGraph();
  assert(g->G[1].firstEdge->adjV == 2);
  assert(g->G[2].firstEdge->adjV == 2);
}

void testCreate() {
  LGraph g = createGraph(3);
  assert(g->G[2].firstEdge == NULL);

  Edge e = (Edge)malloc(sizeof(ENode));
  e->v1 = 1;
  e->v2 = 2;
  e->weight = 2;

  insertEdge(g, e);
  assert(g->G[1].firstEdge->adjV == 2);
  assert(g->G[1].firstEdge->weight == 2);
}

int visited[MaxVertexNum];

void initialVisit() {
  for (size_t i = 0; i < MaxVertexNum; i++) {
    visited[i] = false;
  }
}

void dfs(LGraph g, Vertex v) {
  visited[v] = true; // 标记为已经访问
  printf("正在访问点%d\n", v);
  for (PtrToAdjNode w = g->G[v].firstEdge; w;
       w = w->next) {        // 对v的每一个邻接点adjv
    if (!visited[w->adjV]) { // 如果未访问
      dfs(g, w->adjV);       // 则递归访问
    }
  }
}

void insertToEdge(LGraph g, Edge e, int v1, int v2, int weight) {
  e->v1 = v1;
  e->v2 = v2;
  e->weight = weight;
  insertEdge(g, e);
}

void testDFS() {
  LGraph g = createGraph(6);
  initialVisit();
  Edge e = (Edge)malloc(sizeof(ENode));
  insertToEdge(g, e, 1, 3, 2);
  insertToEdge(g, e, 1, 2, 2);
  insertToEdge(g, e, 1, 5, 2);
  insertToEdge(g, e, 2, 4, 2);
  dfs(g, 1);
  free(e);
}

int main(int argc, char const *argv[]) {
  testDFS();
  // testBuild();
  return 0;
}
