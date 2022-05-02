#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0, lastMax = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      // 为1
      if (nums[i]) {
        max++;
      } else {
        // 不为1
        if (lastMax < max) {
          lastMax = max;
        }
        // 只要为零就重置max
        max = 0;
      }
    }
    return lastMax > max ? lastMax : max;
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr{0, 1, 1, 0, 1, 0, 1, 1};
  cout << s.findMaxConsecutiveOnes(arr);
  return 0;
}
