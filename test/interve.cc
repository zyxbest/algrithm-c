#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
// print vector
void print(vector<int> arr) {
  copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

// 找两个数组的交集
vector<int> intersection(vector<int> arr1, vector<int> arr2) {
  vector<int> res;
  // 求出各自长度
  int size1 = arr1.size(), size2 = arr2.size();

  int i = 0, j = 0;
  // 不超出长度的前提下
  while (i < size1 && j < size2) {
    // 谁小我加谁
    if (arr1[i] < arr2[j]) {
      i++;
    } else if (arr1[i] > arr2[j]) {
      j++;
    } else {
      // 相等同时+1
      res.push_back(arr1[i++]);
      j++;
    }
  }
  return res;
}

// 找多个数组的交集
vector<int> intersection(vector<vector<int>> &arrs) {
  vector<int> result, item;
  for (auto &arr : arrs) {
    // 先排序一遍
    sort(arr.begin(), arr.end());
  }
  // 数组1,2交集
  result = intersection(arrs[0], arrs[1]);

  // 前两个数组的交集必定是后面交集的父集
  // iter遍历result
  for (auto it = result.begin(); it != result.end();) {
    // 从第三个数组开始查找元素是否出现在数组里面
    for (int j = 2; j < arrs.size(); j++) {
      item = arrs[j];
      // 没找到
      if (find(item.begin(), item.end(), *it) == item.end()) {
        // 删除该元素, 并把iter重新赋值, 退出循环
        it = result.erase(it);
        break;
      }
    }
    // 删除元素的话, 跳过该自增
    it++;
  }
  // for (int i = 0; i < result.size(); i++) {
  //   // 从第三个数组开始查找元素是否出现在数组里面
  //   for (int j = 2; j < arrs.size(); j++) {
  //     item = arrs[j];
  //     // 没找到
  //     if (find(item.begin(), item.end(), result[i]) == item.end()) {
  //       // 删除该元素, 退出循环
  //       result.erase(result.begin() + i);
  //       break;
  //     }
  //   }
  // }
  return result;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> arr{
      {1, 2, 3, 4}, {10, 1, 3, 2, 5}, {11, 22, 3, 5, 1}, {121, 1, 4, 0, -1, 3}};
  vector<int> re = intersection(arr);
  print(re);
  return 0;
}
