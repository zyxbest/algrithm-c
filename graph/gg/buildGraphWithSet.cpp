#include <bits/stdc++.h>
using namespace std;

class Graph {
 private:
  int size;
  set<int, greater<int>>* adjList;

 public:
  Graph(int v) {
    size = v;
    adjList = new set<int, greater<int>>[v];
  }

  //  插入边
  void addEdge(int u, int v) {
    adjList[u].insert(v);
    adjList[v].insert(u);
  }

  void printGraph() {
    for (size_t i = 0; i < size; i++) {
      cout << i << " adj are " << endl;
      for (auto& item : adjList[i]) {
        cout << item << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, char const* argv[]) {
  Graph g{5};
  g.addEdge(0, 1);
  g.addEdge(1, 4);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.printGraph();
  return 0;
}
