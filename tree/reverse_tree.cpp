/**
 * @brief 翻转二叉树
 *
 */
#include "include/le_common.h"
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    // outlet
    if (!root) {
      return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }

  // 前序迭代
  TreeNode* invertTreePre(TreeNode* root) {
    if (root) {
      stack<TreeNode*> st;
      st.push(root);
      while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        // 这里就进行了正式的翻转
        swap(node->left, node->right);

        // 前序遍历
        if (node->right) {
          st.push(node->right);  // 右
        }
        if (node->left) {
          st.push(node->left);  // 左
        }
      }
    }
    return root;
  }

  // 层序遍历
  TreeNode* invertTreeLevelTraverse(TreeNode* root) {
    if (root) {
      queue<TreeNode*> q;
      q.push(root);

      while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        swap(node->left, node->right);
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  TreeNode* root = new TreeNode();
  root->val = 1;
  cout << root->val;
  return 0;
}
