/**
 * @brief 是否是满二叉树
 * 满二叉树: 2^h-1
 */

#include "include/le_common.h"

class Solution {
 public:
  int getHeight(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int leftHeight = getHeight(root->left);    // left
    int rightHeight = getHeight(root->right);  // right

    if (leftHeight == -1 || rightHeight == -1) {
      return -1;
    }
    return abs(leftHeight - rightHeight) > 1
               ? -1
               : 1 + max(leftHeight, rightHeight);  // middle
  }

  bool isBalanced(TreeNode* root) { return getHeight(root) != -1; }
};