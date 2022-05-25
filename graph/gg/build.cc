#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  /**
   * 邻接表构造图
   **/

  // m :edge
  // n : points number
  int m, n;
  cin >> n >> m;
  int adjMat[n + 1][n + 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
  }
  return 0;
}
