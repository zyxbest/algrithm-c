#include <bits/stdc++.h>
using namespace std;
void duplicateZeros(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    // 为零
    if (!arr[i]) {
      // 从i到最后 往右移一位
      for (int j = arr.size() - 1; j > i; j--) {
        arr[j] = arr[j - 1];
      }
      i++;
    }
  }
}
void ouput(vector<int> arr) {
  copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
}

int main(int argc, char const* argv[]) {
  vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0}, result{1, 0, 0, 2, 3, 0, 0, 4};
  duplicateZeros(arr);
  ouput(arr);
  return 0;
}
