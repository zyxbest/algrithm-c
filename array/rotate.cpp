// method 3

#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
// 交换元素
void swapArr(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// 翻转数组
void reverse(int arr[], int start, int end) {
  for (size_t i = 0; i < (end - start + 1) / 2; i++) {
    swapArr(arr, start + i, end - i);
  }
}

// 打印数组
void printArr(int arr[]) {
  copy(arr, arr + 5, ostream_iterator<int>(cout, " "));
}

void testReverse() {
  int arr[5] = {1, 2, 3, 4, 5};
  reverse(arr, 0, 4);
  assert(arr[0] == 5 && arr[1] == 4);
}

void preRotate(int arr[], int n, int size) {
  reverse(arr, 0, n - 1);
  reverse(arr, n, size - 1);
  reverse(arr, 0, size - 1);
}

void testPreRotate() {
  int arr[5] = {1, 2, 3, 4, 5};
  preRotate(arr, 2, 5);



  printArr(arr);
}

int main(int argc, char const *argv[]) {
  // testReverse();
  testPreRotate();
  return 0;
}
