#include "include/le_common.h"

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> arr;
    preorderTraversalProcess(root, arr);
    return arr;
  }

  void preorderTraversalProcess(TreeNode* root, vector<int>& arr) {
    if (!root) {
      return;
    }
    arr.push_back(root->val);
    preorderTraversalProcess(root->left, arr);
    preorderTraversalProcess(root->right, arr);
  }

  // 先序遍历
  vector<int> preOrder(TreeNode* root) {
    TreeNode* temp = root;
    stack<TreeNode*> stack;
    vector<int> arr;
    while (temp || !stack.empty()) {
      // 一直遍历到最左子树
      while (temp) {
        arr.push_back(temp->val);
        stack.push(temp);
        temp = temp->left;
      }
      // 弹出一个, 从右子树继续遍历
      if (!stack.empty()) {
        temp = stack.top();
        stack.pop();
        temp = temp->right;
      }
    }
    return arr;
  }

  // 先序遍历, 根右左
  vector<int> preOrder(TreeNode* root) {
    if (!root) {
      return {};
    }

    TreeNode* temp;
    stack<TreeNode*> stack;
    vector<int> arr;

    stack.push(root);
    while (!stack.empty()) {
      temp = stack.top();
      stack.pop();
      arr.push_back(temp->val);
      if (temp->right) {
        stack.push(temp->right);
      }
      if (temp->left) {
        stack.push(temp->left);
      }
    }
    return arr;
  }

  // 中序遍历
  vector<int> inOrder(TreeNode* root) {
    if (!root) {
      return {};
    }

    TreeNode* temp = root;
    stack<TreeNode*> stack;
    vector<int> res;

    while (temp || !stack.empty()) {
      while (temp) {
        stack.push(temp);
        temp = temp->left;
      }

      if (!stack.empty()) {
        temp = stack.top();
        stack.pop();
        res.push_back(temp->val);
        temp = temp->right;
      }
    }
    return res;
  }

  vector<int> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    queue<TreeNode*> queue;
    vector<int> arr;

    queue.push(root);
    TreeNode* node;
    while (!queue.empty()) {
      node = queue.front();
      if (node->left) {
        queue.push(node->left);
      }
      if (node->right) {
        queue.push(node->right);
      }
      queue.pop();
      arr.emplace_back(node->val);
    }
    return arr;
  }
};