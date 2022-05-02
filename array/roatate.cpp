// #include <bits/stdc++.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

// method1: 每次移动一个
void rotateArr(int *arr, int n) {
  for (int times = 0; times < n; times++) {
    int temp = arr[0];
    for (size_t i = 1; i < 7; i++) {
      arr[i - 1] = arr[i];
    }
    arr[6] = temp;
  }
}

void test(int *arr, int size) {
  for (size_t i = 0; i < size; i++) {
    cout << arr[i];
  }
}

// mehod2: 每次前移多位
// n/k * k = n

// 1 2 3 4 5
// 2

// 3 x 5 x 1
void preRotate(int *arr, int n, int size) {
  // 从第n+1位开始
  for (int k = n - 1; k >= 0; k--) {
    int i = n + k, temp = arr[k];
    while (i < size) {
      arr[i - n] = arr[i];
      i += n;
    }
    arr[i - n - 1] = temp;
  }
}

int main(int argc, char const *argv[]) {
  int arr[5] = {
      1, 2, 3, 4, 5,
  };
  int size = sizeof(arr) / sizeof(int);

  // rotateArr(arr, 2);
  preRotate(arr, 2, size);
  test(arr, size);
  return 0;
}
