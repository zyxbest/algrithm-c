/**
 * @brief 完全二叉树的节点个数
 * 满二叉树: 2^h-1
 */

#include "include/le_common.h"

class Solution {
 public:
  //  简单的方法
  int nums(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return nums(root->left) + nums(root->right) + 1;
  }

  int nums(TreeNode* root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int res{};
    while (!q.empty()) {
      int size = q.size();
      res += size;
      for (size_t i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return res;
  }

  // O()
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int leftHeight{1}, rightHeight{1};  // 初始化为1, 已经有一层了, 为root
    while (left) {
      left = left->left;
      leftHeight++;
    }
    while (right) {
      right = right->right;
      rightHeight++;
    }
    if (leftHeight == rightHeight) {
      // 个数 2^h - 1
      return (1 << leftHeight) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
