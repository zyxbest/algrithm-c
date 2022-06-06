#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph =
        buildGraph(equations, values);
    vector<double> res;
    for (auto& vec : queries) {
      // 每次遍历新建一个visited map
      unordered_map<string, bool> visited{};
      string start = vec[0];
      string end = vec[1];
      // 错误检测, 说明有点没进入图中
      if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
        res.push_back(-1.0);
        continue;
      }
      res.push_back(getPathWeight(graph, vec[0], vec[1], visited));
    }
    return res;
  }

 private:
  unordered_map<string, unordered_map<string, double>> buildGraph(
      vector<vector<string>>& equations, vector<double>& values) {
    unordered_map<string, unordered_map<string, double>> graph;
    string f, t;
    for (size_t i = 0; i < equations.size(); i++) {
      f = equations[i][0];
      t = equations[i][1];
      // 加权有向图
      graph[f][t] = values[i];
      graph[t][f] = 1.0 / values[i];
    }
    return graph;
  }

  double getPathWeight(
      unordered_map<string, unordered_map<string, double>>& graph,
      const string& start, string& end, unordered_map<string, bool>& visited) {
    // 避免了没找到的情况
    // 找到了
    if (graph[start].find(end) != graph[start].end()) {
      return graph[start][end];
    }
    visited[start] = true;
    for (auto& [key, weight] : graph[start]) {
      // 没访问过就为false, 访问过, 再把它设为true
      if (!visited[key]) {
        double productWeight = getPathWeight(graph, key, end, visited);
        if (productWeight != -1.0) {
          return weight * productWeight;
        }
      }
    }
    return -1.0;
  }
};

void test1() {
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

  Solution s;
  s.calcEquation(equations, values, queries);
}

int main(int argc, char const* argv[]) {
  vector<vector<string>> equations{
      {"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
  vector<double> values = {3.0, 4.0, 5.0, 6.0};
  vector<vector<string>> queries = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"},
                                    {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
  Solution s;
  vector<double> res = s.calcEquation(equations, values, queries);

  copy(res.begin(), res.end(), ostream_iterator<double>(cout, " "));
  return 0;
}
