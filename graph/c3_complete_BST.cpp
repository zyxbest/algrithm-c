// 完全二叉搜索树
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
#define MaxSize 100

int arr[MaxSize], root[MaxSize];

bool compare(int a, int b) { return a < b; }

int getLeftLength(int n) {
  int layers = (int)log2(n);
  int leftChild = pow(2, layers) - 1;
  int lastLayerNum = n - pow(2, layers);
  int leftLast = min((int)ceil(layers / 2), lastLayerNum);

  // int a = (int)pow(2, n);
  return leftChild + leftLast;
}

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
  int LRoot = Root * 2 + 1;
  int RRoot = LRoot + 1;
  resolve(L, L + LChild, LRoot);
  resolve(L + LChild + 1, R, RRoot);
}

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
  resolve(0, n, 0);
}

void powt(int n);
int main(int argc, char const *argv[]) {
  input();
  // powt(3);
  return 0;
}

// test

void powt(int n) {
  cout << round(log2(10)) << "\n";
  cout << exp(1);
  cout << (int)pow(2, n);
}