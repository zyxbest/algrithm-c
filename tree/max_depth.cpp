/**
 * @brief 二叉树的最大深度
 *
 */

#include "include/le_common.h"

class Solution {
 public:
  int result;  // for 前序
  int maxDepth(TreeNode* root) {
    // 空节点说明父节点只有一个或0个子节点
    // 也就是说当前高度为0
    if (!root) {
      return 0;
    }
    // 左右孩子树最大的再加上1
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  // 层序遍历计算最大深度
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int depth{};
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      depth++;  // 记录层数
      // 层序遍历
      for (size_t i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }
    return depth;
  }

  // 前序遍历
  void getDepth(TreeNode* root, int depth) {
    result = max(depth, result);  // 中
    if (!root->left && !root->right) {
      return;
    }
    if (root->left) {
      getDepth(root->left, depth + 1);  // 左
    }
    if (root->right) {
      getDepth(root->right, depth + 1);  // 右
    }
    return;
  }

  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    getDepth(root, 1);
    return result;
  }
};