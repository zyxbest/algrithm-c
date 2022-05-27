#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 private:
  vector<int> root;
  vector<int> size;

 public:
  //  这边为什么要初始化 成员变量的长度呢
  // 不初始化, 就不可以使用
  UnionFind(int sz) : root(sz), size(sz) {
    for (int i = 0; i < sz; i++) {
      root[i] = i;
    }
  }

  int find(int x) {
    if (x == root[x]) {
      return x;
    }
    return root[x] = find(root[x]);
  }

  void unionSet(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    // 始终root1  size  < root2
    if (root1 != root2) {
      if (size[root2] > size[root1]) {
        int temp = root2;
        root2 = root1;
        root1 = temp;
      }
      root[root1] = root2;
      size[root2] = size[root1] + size[root2];
      // size.erase(root1);
    }
  }

  bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int sz = isConnected.size();
    UnionFind uf(sz);
    // 遍历邻接矩阵的右上半边
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        // 如果为1 表示相接
        if (isConnected[i][j]) {
          uf.unionSet(i, j);
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < sz; i++) {
      // 相等表示一个省
      if (i == uf.find(i)) {
        sum++;
      }
    }
    return sum;
  }
};

// test

void testUnionFind() {
  UnionFind uf(10);
  // 1-2-5-6-7 3-8-9 4
  uf.unionSet(1, 2);
  uf.unionSet(2, 5);
  uf.unionSet(5, 6);
  uf.unionSet(6, 7);
  uf.unionSet(3, 8);
  uf.unionSet(8, 9);
  assert(uf.connected(1, 5));   // true
  assert(uf.connected(5, 7));   // true
  assert(!uf.connected(4, 9));  // false
  // 1-2-5-6-7 3-8-9-4
  uf.unionSet(9, 4);
  assert(uf.connected(4, 9));  // true
}

int main(int argc, char const* argv[]) {
  testUnionFind();
  vector<vector<int>> arr{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  Solution s;
  cout << s.findCircleNum(arr);

  return 0;
}
