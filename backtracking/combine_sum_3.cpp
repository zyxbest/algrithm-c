/**
 * @brief 组合3
 * https://leetcode.cn/problems/combination-sum-iii/
 */

#include "include.h"

class Solution {
 private:
  vector<vector<int>> result;  // 存放结果集
  vector<int> path;            // 符合条件的结果

  int n;  // 目标和
  int k;  // k个数的集合

  // 1. 确定递归函数参数
  void backtracking(int index, int sum) {
    if (sum > n) {
      return;
    }

    // 2. 终止条件
    if (path.size() == k) {
      if (sum == n) {
        result.push_back(path);
      }
      return;
    }

    // 3. 单层搜索过程
    for (int i = index; i <= 9 - (k - path.size()) + 1; i++) {
      path.push_back(i);
      backtracking(i + 1, sum + i);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    this->k = k;
    this->n = n;
    backtracking(1, 0);
    return result;
  }
};