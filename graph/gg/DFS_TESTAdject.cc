#include <bits/stdc++.h>
using namespace std;
class Graph {
 private:
  map<int, bool> visited;
  map<int, list<int>> adj;

 public:
  void addEdge(int v, int w);
  void DFSUtil(int v);
  void DFS();
};

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::DFSUtil(int v) {
  // 一进来就是未访问过的
  visited[v] = true;
  cout << v << " ";
  for (auto &u : adj[v]) {
    // 没访问过的再递归
    if (!visited[u]) {
      DFSUtil(u);
    }
  }
}

// 防止有未连接的图
void Graph::DFS() {
  for (auto &item : adj) {
    int v = item.first;
    if (!visited[v]) {
      DFSUtil(v);
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
  g.DFS();
  return 0;
}
