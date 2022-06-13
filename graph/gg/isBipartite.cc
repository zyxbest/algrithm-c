/*
* 邻接矩阵法寻找是否是 Bipartite
时间复杂度 O(V^2) : V 顶点个数
 */

#include <bits/stdc++.h>
using namespace std;
#define V 4

bool isBipartiteUtil(int g[][V], int src, vector<int> colors) {
  colors[src] = 1;

  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (size_t i = 0; i < V; i++) {
      // 有边
      if (g[u][i]) {
        // 没有访问过
        if (colors[i] == -1) {
          colors[i] = 1 - colors[u];
          q.push(i);
          // 相邻的点 是同一种颜色的话, 说明错了
        } else if (colors[u] == colors[i]) {
          return false;
        }
      }
    }
  }
  return true;
}

bool isBipartite(int g[][V]) {
  // 初始化 -1
  vector<int> colors{V, -1};

  // 防止是不连接的图
  for (size_t i = 0; i < V; i++) {
    // 未访问的点
    if (colors[i] == -1) {
      // 1假为假
      if (!isBipartiteUtil(g, i, colors)) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int G[][V] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
  cout << (isBipartite(G) ? "Yes" : "No");
  return 0;
}
