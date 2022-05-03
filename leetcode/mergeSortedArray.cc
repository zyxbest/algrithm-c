#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i{}, j{};  // nums1, nums2 index
  while (i < m + 1 && j < n + 1) {
    // 找到一个比nums2大的元素, nums1右移
    if (nums1[i] > nums2[j]) {
      for (int k = m - 1; k > i; k--) {
        nums1[k] = nums1[k - 1];
      }
      // nums2插入到正确的位置上
      nums1[i++] = nums2[j++];
    } else if (nums1[i]) {
      // nums1 < nums2
      i++;
    } else {
      // nums1为零
      nums1[i++] = nums2[j++];
    }
  }
}

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  merge(nums1, 6, nums2, 3);
  // print arr
  copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
