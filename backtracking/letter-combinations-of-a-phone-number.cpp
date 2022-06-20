/**
 * @brief 电话号码的字母组合
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 */

#include "include.h"

class Solution {
 private:
  vector<string> result;
  string path;
  string digits;  // copy
  const string maps[10]{
      "",      // 0
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9
  };

  void backtracking(int index) {
    // 结束
    if (index == digits.size()) {
      result.push_back(path);
      return;
    }

    // 加上下面就错了
    // for (int i = index; i < digits.size(); i++) {
    for (auto &ch : maps[digits[index] - '0']) {
      path.push_back(ch);
      backtracking(index + 1);
      path.pop_back();
    }
    // }
  }

 public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() > 0) {
      this->digits = digits;
      backtracking(0);
    }
    return result;
  }
};
