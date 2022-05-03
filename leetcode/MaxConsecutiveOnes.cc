#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int m = 0, lastMax = 0;
    for (auto& num : nums) {
      // 为1
      if (num) {
        m++;
      } else {
        // 不为1
        if (lastMax < m) {
          lastMax = m;
        }
        // 只要为零就重置max
        m = 0;
      }
    }
    return max(lastMax, m);
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr{0, 1, 1, 0, 1, 0, 1, 1};
  cout << s.findMaxConsecutiveOnes(arr);
  return 0;
}
