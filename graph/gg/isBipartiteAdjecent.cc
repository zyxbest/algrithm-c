/*
* 邻接表法寻找是否是 Bipartite
时间复杂度 O(V^2) : V 顶点个数
 */

#include <bits/stdc++.h>
using namespace std;

enum Hel {
  UNVISITED = -1,  // 未访问过
  COL,             // 第一种颜色
  SUM              // 总和
};
bool isBipartiteAnswer(int V, vector<int> adj[]) {
  // vector to store colour of vertex
  // assigning all to -1 i.e. uncoloured
  // colours are either 0 or 1
  // for understanding take 0 as red and 1 as blue
  vector<int> col(V, -1);

  // queue for BFS storing {vertex , colour}
  queue<pair<int, int>> q;

  // loop incase graph is not connected
  for (int i = 0; i < V; i++) {
    // if not coloured
    if (col[i] == -1) {
      // colouring with 0 i.e. red
      q.push({i, 0});
      col[i] = 0;

      while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        // current vertex
        int v = p.first;
        // colour of current vertex
        int c = p.second;

        // traversing vertexes connected to current vertex
        for (int j : adj[v]) {
          // if already coloured with parent vertex color
          // then bipartite graph is not possible
          if (col[j] == c) return 0;

          // if uncoloured
          if (col[j] == -1) {
            // colouring with opposite color to that of parent
            col[j] = (c) ? 0 : 1;
            q.push({j, col[j]});
          }
        }
      }
    }
  }
  // if all vertexes are coloured such that
  // no two connected vertex have same colours
  return 1;
}

bool isBipartite(int V, vector<int> adj[]) {
  // 因为初始化写成了大括号, 导致出错
  // 浪费大量时间
  vector<int> colors(V, UNVISITED);
  queue<int> q;
  for (size_t i = 0; i < V; i++) {
    if (colors[i] == UNVISITED) {
      q.push(i);
      colors[i] = COL;
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
          if (colors[v] == colors[u]) {
            return false;
          }
          if (colors[v] == UNVISITED) {
            q.push(v);
            // 另一种颜色
            colors[v] = SUM - colors[u];
          }
        }
      }
    }
  }
  return true;
}

bool isBipartite2(int V, vector<int> adj[]) {
  // 初始化 -1
  vector<int> colors{V, -1};
  queue<pair<int, int>> q;

  // 防止是不连接的图
  for (size_t i = 0; i < V; i++) {
    // 未访问的点
    if (colors[i] == -1) {
      colors[i] = 0;
      q.push({i, 0});
      while (!q.empty()) {
        pair<int, int> p = q.front();
        int u = p.first;
        int c = p.second;
        q.pop();
        for (auto &v : adj[u]) {
          if (colors[v] == c) {
            return false;
          } else if (colors[v] == -1) {
            // 1 时为 0
            // 0 时为 1
            colors[v] = 1 - c;
            q.push({v, colors[v]});
          }
        }
      }
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  // int G[][V] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
  // cout << (isBipartite(G) ? "Yes" : "No");

  int V, E;
  V = 4, E = 8;
  // adjacency list for storing graph
  vector<int> adj[V];
  adj[0] = {1, 2, 3};
  adj[1] = {0, 2};
  adj[2] = {0, 1, 3};
  adj[3] = {0, 2};

  bool ans = isBipartiteAnswer(V, adj) == isBipartite(V, adj);
  // returns 1 if bipartite graph is possible
  if (ans) cout << "Yes\n";
  // returns 0 if bipartite graph is not possible
  else
    cout << "No\n";
  return 0;
}
