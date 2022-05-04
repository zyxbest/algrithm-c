#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define MaxSize 20

// 生成随机的数组,长度为20
vector<int> generate() {
  vector<int> arr;
  for (size_t i = 0; i < MaxSize; i++) {
    arr.push_back(rand() * MaxSize + 1);
  }
  return arr;
}

// 打印數組，使用iterator
void output(vector<int> &nums) {
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

// 比较器
void compare(vector<int> &nums, vector<int> &nums2) {
  for (int i = 0; i < nums.size(); i++) {
    assert(nums[i] == nums2[i]);
  }
}

// 选择排序
void selectionSort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    int small = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[small] > nums[j]) {
        small = j;
      }
    }
    if (i != small) {
      swap(nums[i], nums[small]);
    }
  }
}

// 冒泡排序
void bubbleSort(vector<int> &nums) {
  for (int i = nums.size() - 1; i >= 0; i--) {
    for (size_t j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
      }
    }
  }
}

// 插入排序
void insertionSort(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {
      swap(nums[j], nums[j - 1]);
    }
  }
}

// 归并排序
void merge(vector<int> &arr, int l, int m, int r) {
  int size = r - l + 1;
  int *help = (int *)malloc(sizeof(int) * size);
  int p1 = l;
  int p2 = m + 1;
  int i = 0;
  // 较小的放在前面
  while (p1 <= m && p2 <= r) {
    help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
  }

  // 其余的依次填入
  while (p1 <= m) {
    help[i++] = arr[p1++];
  }

  while (p2 <= r) {
    help[i++] = arr[p2++];
  }

  // arr 原址排序
  for (int j = 0; j < size; j++) {
    arr[l + j] = help[j];
  }
}

// 就是因为这里没有加上 & 符号,导致我追bug追了半天,这个意思是传入指针,可以修改的
void process(vector<int> &nums, int l, int r) {
  if (l == r) {
    return;
  }
  int mid = l + ((r - l) >> 1);
  process(nums, l, mid);
  process(nums, mid + 1, r);
  merge(nums, l, mid, r);
}

void mergeSort(vector<int> &nums) {
  if (nums.size() < 2) {
    return;
  }
  process(nums, 0, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
  vector<int> arr = generate();
  vector<int> copy = arr, insertion = arr, mergetion = arr;
  bubbleSort(arr);
  selectionSort(copy);
  insertionSort(insertion);
  mergeSort(mergetion);

  // 比较是否一致
  compare(arr, copy);
  compare(mergetion, insertion);
  output(copy);

  return 0;
}
