#if !defined(LE_COMMON)
#define LE_COMMON

#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#endif  // LE_COMMON
