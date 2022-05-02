#include <bits/stdc++.h>
using namespace std;
// 数字有多少位
int numSize(int num) {
  int res = 0;
  // 每次除以10
  while (num) {
    num /= 10;
    res++;
  }
  return res;
}

class Solution {
 private:
  int numSize(int num) {
    int res = 0;
    // 每次除以10
    while (num) {
      num /= 10;
      res++;
    }
    return res;
  }

 public:
  int findNumbers(vector<int>& nums) {
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      // 如果是偶数位,即numSize(nums[i])可以整除2
      if (!(numSize(nums[i]) % 2)) {
        result++;
      }
    }
    return result;
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr{12, 345, 2, 6, 7896};
  cout << numSize(2) << endl;
  cout << s.findNumbers(arr);
  return 0;
}
