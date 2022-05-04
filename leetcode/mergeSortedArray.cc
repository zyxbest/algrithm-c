#include <bits/stdc++.h>
using namespace std;
/* #1: my solution */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  // nums2不为空
  if (n) {
    int i{}, j{};  // nums1, nums2 index
    int msize = m + n;
    while (i < msize && j < n) {
      // 找到一个比nums2大的元素
      if (nums1[i] > nums2[j]) {
        //  nums1右移
        for (int k = msize - 1; k > i; k--) {
          nums1[k] = nums1[k - 1];
        }
        // nums2插入到正确的位置上
        nums1[i++] = nums2[j++];
      } else if (!nums1[i] && i >= m + j) {
        // nums1为零, 并且是最后的几个0
        nums1[i++] = nums2[j++];
      } else {
        // nums1 < nums2
        i++;
      }
    }
  }
}

/* #2: two line solution */
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  for (int i = 0; i < n; i++) {
    nums1[m + i] = nums2[i];
  }
  sort(nums1.begin(), nums1.end());
}

/* #3: most voted */
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i = m - 1, j = n - 1, k = m + n - 1;
  while (i >= 0 && j >= 0) {
    nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
  }
  while (j >= 0) {
    nums1[k--] = nums2[j--];
  }
}

void test1() {
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  merge2(nums1, 3, nums2, 3);
  // print arr
  copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void test2() {
  vector<int> nums1{1};
  vector<int> nums2{};
  merge2(nums1, 1, nums2, 0);
  // print arr
  copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void test3() {
  vector<int> nums1{-1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0};
  vector<int> nums2{-1, -1, 0, 0, 1, 2};
  merge2(nums1, 5, nums2, 6);
  // print arr
  copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
void testAll() {
  test1();
  test2();
  test3();
}

int main(int argc, char const* argv[]) {
  testAll();
  return 0;
}
