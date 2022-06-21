/**
 * @brief 组合
 * https://leetcode.cn/problems/combination-sum/
 */
#include <include.h>
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  int target;
  vector<int> candidates;
  void backtracking(int index, int sum) {
    if (sum == target) {
      result.push_back(path);
      return;
    }

    // 如果大于的话, 就停止遍历
    for (int i = index; i < candidates.size() && sum + candidates[i] <= target;
         i++) {
      int num = candidates[i];
      path.push_back(num);
      backtracking(index, sum + num);  // 深度里, 可以使用重复的值
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->target = target;
    this->candidates = candidates;
    backtracking(0, 0);
    return result;
  }
};