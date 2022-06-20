/**
 * @brief 组合
 *
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
    } else if (sum > target) {
      return;
    }

    for (int i = index; i <= candidates.size(); i++) {
      int num = candidates[i];
      path.push_back(num);
      backtracking(index, sum + num);
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