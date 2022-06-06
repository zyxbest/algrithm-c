#include <bits/stdc++.h>
using namespace std;
class Graph {
 private:
  vector<vector<int>> graph;

 public:
  Graph(int n) { graph.resize(n); }

  void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  void printGraph() {
    cout << "size is " << graph.size();
    copy(graph.begin(), graph.end(), ostream_iterator<int>(cout, " "));
  }
};

int main(int argc, char const *argv[]) {
  Graph g{5};
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.printGraph();
  return 0;
}
