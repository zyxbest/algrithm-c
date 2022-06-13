/*
 * 二叉树用图表示
 * index层有多少个节点
 */

#include <bits/stdc++.h>
using namespace std;
class Graph {
 private:
  map<int, list<int>> adj;

 public:
  void addEdge(int u, int v);
  int BFS(int l);
};

void Graph::addEdge(int u, int v) { adj[u].push_back(v); }

int Graph::BFS(int l) {
  map<int, int> level;
  map<int, bool> visited;
  queue<int> q;
  q.push(0);          // 先放入根节点
  visited[0] = true;  // 根节点已访问
  level[0] = 0;       // 层数从零开始

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        // 下一层层数 = 上一层 +1
        level[v] = level[u] + 1;
        q.push(v);
      }
    }
  }

  // 第l层有多少个节点
  int res = 0;
  for (auto &item : level) {
    if (item.second == l) {
      res++;
    }
  }
  return res;
}

int main() {
  // Create a graph given
  // in the above diagram
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(2, 5);

  int level = 2;

  cout << g.BFS(level);

  return 0;
}