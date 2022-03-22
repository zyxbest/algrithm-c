// 完全二叉搜索树
#include <algorithm>
#include <iostream>

using namespace std;
#define MaxSize 100

int arr[MaxSize], root[MaxSize];

bool compare(int a, int b) { return a < b; }

int getLeftLength(int n) { return n; }

/**
 * @brief 要把中间的元素放到根节点上
 *
 */
void resolve(int L, int R, int Root) {
  int n = R - L + 1;
  if (n == 0) {
    return;
  }

  int LChild = getLeftLength(n);
  root[Root] = arr[L + LChild];

  resolve(L,LChild,)
}

int arr[MaxSize];
void input() {
  int n;
  cout << "请输入个数: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n, compare);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main(int argc, char const *argv[]) {
  input();

  return 0;
}
