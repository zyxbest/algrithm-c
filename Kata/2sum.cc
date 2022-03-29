#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> m;
    for (size_t i = 0; i < nums.size(); i++) {
      int num = nums[i];
      int minus = target - num;
      m[target - num] = i;
    }
    int i = 0;
    for (int num : nums) {
      if (m.count(num) && i != m[num]) {
        return {i, m[num]};
      }
      i++;
    }

    return {0, 0};
  }
};