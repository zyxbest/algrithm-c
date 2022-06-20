/**
 * @brief 二叉树的最小深度
 *
 */

#include "include/le_common.h"

class Solution {
 public:
  /**
   * @brief 计算最短的深度
   * 只有叶节点才需要计算深度, 否则的话, 不计算
   * 这一点和最大深度不一样
   *
   * @param root
   * @return int
   */
  int minDepth(TreeNode* root) {
    if (root) {
      // 叶节点, 子节点都不存在
      if (!(root->left || root->right)) {
        return 1;
      } else if (root->left && root->right) {
        // 都存在就竞争一下
        return 1 + min(minDepth(root->left), minDepth(root->right));
      } else {
        // 左右节点不是都存在
        // 返回存在的那个节点的深度
        return 1 + minDepth(root->left ? root->left : root->right);
      }
    } else {
      // 只有初始为空的时候才会走到这里
      return 0;
    }
  }

  // 大神写的
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    // 存在一个子节点
    if (root->left && !root->right) {
      return 1 + minDepth(root->left);
    }
    if (root->right && !root->left) {
      return 1 + minDepth(root->right);
    }

    // 正常情况
    return 1 + min(minDepth(root->left), minDepth(root->right));
  }

  // 层序遍历迭代法
  int minDepthLevelIter(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int depth{};  // 当前层数(深度)
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      depth++;  // 记录深度
      for (size_t i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        // 子节点都为空, 说明是最小深度, 返回
        if (!(node->left || node->right)) return depth;
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
};