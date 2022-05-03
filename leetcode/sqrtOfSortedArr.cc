#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
vector<int> solution(vector<int>& nums) {
  vector<int> result;
  for (size_t i = 0; i < nums.size(); i++) {
    result.push_back(nums[i] * nums[i]);
  }

  sort(result.begin(), result.end());
  /*   // bubble sort
    for (int j = result.size() - 1; j >= 0; j--) {
      for (size_t i = 0; i < j; i++) {
        if (result[i] > result[i + 1]) {
          swap(result[i], result[i + 1]);
        }
      }
    } */
  return result;
}
int main(int argc, char const* argv[]) {
  vector<int> arr{-4, -1, 0, 3, 10};
  vector<int> result = solution(arr);

  copy(result.begin(), result.end(), ostream_iterator<int>(cout, ", "));

  return 0;
}
