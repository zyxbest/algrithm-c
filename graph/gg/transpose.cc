#include <bits/stdc++.h>
using namespace std;

class Graph {
 private:
  vector<vector<int>> adj;

 public:
  Graph(int n) { adj.resize(n); }
  //  有向图
  void addEdge(int u, int v) { adj[u].push_back(v); }

  void tranverse(Graph &trans) {
    for (size_t i = 0; i < trans.adj.size(); i++) {
      for (auto &item : adj[i]) {
        trans.adj[item].push_back(i);
      }
    }
  }

  void print() {
    for (size_t i = 0; i < adj.size(); i++) {
      cout << i << " --> ";

      for (auto &item : adj[i]) {
        cout << item << " ";
      }
      cout << endl;
    }
  };
};

int main(int argc, char const *argv[]) {
  Graph g{5}, rever{5};
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(0, 3);
  g.addEdge(2, 0);
  g.addEdge(3, 2);
  g.addEdge(4, 1);
  g.addEdge(4, 3);
  g.print();
  g.tranverse(rever);
  rever.print();
  return 0;
}