

#include <bits/stdc++.h>
using namespace std;

class Graph {
 private:
  map<int, bool> visited;
  map<int, list<int>> adj;

 public:
  void addEdge(int v, int w);
  void DFS(int v);
  void DFSUnconnected();
};

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

// 递归实现 深度优先遍历
void Graph::DFS(int v) {
  visited[v] = true;
  cout << v << " ";
  for (auto item : adj[v]) {
    // 邻接点没有访问过, 就继续 dfs
    if (!visited[item]) {
      DFS(item);
    }
  }
}

// 访问所有的节点, 因为graph可能不是连通图(任意两个顶点都连通)
void Graph::DFSUnconnected() {
  for (auto item : adj) {
    // 没有访问过
    if (!visited[item.first]) {
      // 就访问
      DFS(item.first);
    }
  }
}

int main(int argc, char const *argv[]) {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal"
          " (starting from vertex 2) \n";
  g.DFS(2);
  return 0;
}
