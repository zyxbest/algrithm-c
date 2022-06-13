/**
 * @brief detect cycle in graph
 *
 */
#include <bits/stdc++.h>

using namespace std;
// typedef map<int, vector<int>> AdjList;

using AdjList = vector<vector<int>>;

class Graph {
 private:
  int V;
  AdjList adj;
  bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recursive);

 public:
  Graph(int v);
  void addEdge(int u, int v);
  bool isCyclic();
};

/**
 * @brief Construct a new Graph:: Graph object
 *
 * @param v vertices
 */
Graph::Graph(int v) {
  this->V = v;
  adj.resize(V);
}

bool Graph::isCyclic() {
  vector<bool> visited(V, false);
  vector<bool> recursive(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCyclicUtil(i, visited, recursive)) {
      return true;
    }
  }
  return false;
}

bool Graph::isCyclicUtil(int v, vector<bool> &visited,
                         vector<bool> &recursive) {
  // 未访问过
  if (!visited[v]) {
    visited[v] = true;
    recursive[v] = true;
    // 对于每一个邻接点
    for (auto &u : adj[v]) {
      // 没访问过, 且有环
      if (!visited[u] && isCyclicUtil(u, visited, recursive)) {
        return true;
      } else if (recursive[u]) {
        return true;
      }
    }
  }
  recursive[v] = false;
  return false;
}

void Graph::addEdge(int u, int v) { adj[u].push_back(v); }

int main() {
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  if (g.isCyclic())
    cout << "Graph contains cycle";
  else
    cout << "Graph doesn't contain cycle";
  return 0;
}