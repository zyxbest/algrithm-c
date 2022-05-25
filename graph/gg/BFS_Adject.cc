/*
 * Created on Wed May 25 2022
 * 广度优先搜索
 * Copyright (c) 2022 Your Company
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
 private:
  int V;
  // 邻接表 表示图
  vector<list<int> > adj;

 public:
  Graph(int V);
  void addEdge(int v, int w);
  // 从s的bfs遍历
  void bfs(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adj.resize(V);
}

// 增加一条从v到w的边
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

// 广度优先搜索
void Graph::bfs(int s) {
  cout << "BFS (Breadth First Search) from v " << s << endl;

  vector<bool> visited(V, false);
  list<int> queue;
  queue.push_back(s);
  visited[s] = true;
  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    cout << s << " ";
    for (auto adjecent : adj[s]) {
      if (!visited[adjecent]) {
        visited[adjecent] = true;
        queue.push_back(adjecent);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.bfs(2);
  return 0;
}
