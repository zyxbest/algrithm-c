/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include <algorithm>
#include <bitset>
#include <string>

#include <cmath>
// @lc code=start
using namespace std;
#include <iostream>
class Solution {
public:
  int hammingDistance(int x, int y) {
    string sx = bitset<32>(x).to_string();
    string sy = bitset<32>(y).to_string();
    int bitorr = bitset<32>(x ^ y).count();
    cout << sx << "\n";
    cout << sy << "\n";
    cout << bitorr << "\n";

    return bitorr;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution solution;
  // cout << solution.hammingDistance(1577962638, 1727613287);
  cout << solution.hammingDistance(1, 4);

  return 0;
}
