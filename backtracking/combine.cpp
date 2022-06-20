/**
 * @brief 组合
 * https://leetcode.cn/problems/combinations/
 *
 */

#include "include.h"

class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;  // 每个结果
  int n, k;
  int delta;  // n - k
  void backtracking(int index) {
    // 结束条件
    if (path.size() == k) {
      result.push_back(path);
      return;
    }

    // 宽度
    // 剪枝
    for (int i = index; i <= delta + path.size() + 1; i++) {
      path.push_back(i);
      // 递归遍历深度
      backtracking(i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    this->n = n;
    this->k = k;
    this->delta = n - k;
    backtracking(1);
    return result;
  }
};