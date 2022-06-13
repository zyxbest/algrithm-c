#include <bits/stdc++.h>
using namespace std;
class Graph {
 private:
  map<int, list<int>> adj;
  int v;
  int num{};

 public:
  void addEdge(int u, int v) { adj[u].push_back(v); }
  void DFS(int u) {
    for (auto v : adj[u]) {
      // 找到了
      if (v == this->v) {
        (this->num)++;
      }

      cout << v << " ";
      DFS(v);
    }
  }

  // 无环图可以使用这种方式
  // 不设访问列表的dfs
  int countPaths(int u, int v) {
    this->v = v;
    DFS(u);
    return this->num;
  }
};

int main() {
  // Create a graph given in the above diagram - see link
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 4);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(2, 1);
  // g.addEdge(3, 2);
  // Validate it...
  cout << g.countPaths(0, 4);
}