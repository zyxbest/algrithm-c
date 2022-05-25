#include <bits/stdc++.h>
using namespace std;

// 插入边
void addEdge(vector<int> arr[], int v, int u) {
  arr[v].push_back(u);
  arr[u].push_back(v);
}

void printGraph(vector<int> arr[], int V) {
  for (int i = 0; i < V; i++) {
    cout << "\n Adjacency list of vectex " << i << "\n head ";
    for (auto v : arr[i]) {
      cout << "-> " << v;
    }
  }
}

int main(int argc, char const *argv[]) {
  int V = 5;
  vector<int> arr[V];
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  printGraph(adj, V);
  return 0;
}
