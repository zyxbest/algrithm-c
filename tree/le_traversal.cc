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
  vector<int> preOrderAno(TreeNode* root) {
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

  // 后序遍历
  // 根弹出的时候, 放入左右, 把根放入res栈
  vector<int> inOrderAno(TreeNode* root) {
    if (!root) {
      return {};
    }

    // 根右左的顺序入res栈
    stack<TreeNode*> st, res;
    vector<int> arr;
    st.push(root);
    while (!st.empty()) {
      root = st.top();
      st.pop();
      res.push(root);
      if (root->left) {
        st.push(root->left);
      }
      if (root->right) {
        st.push(root->right);
      }
    }

    // 左右根的顺序出res栈
    while (!res.empty()) {
      arr.emplace_back(res.top()->val);
      res.pop();
    }
    return arr;
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    queue<TreeNode*> queue;
    vector<vector<int>> res;
    vector<int> arr;

    queue.push(root);
    TreeNode* node;
    // 当前层的个数
    int currSize = 1;
    // 下一层的个数
    int nextLevelSize = 0;
    while (!queue.empty()) {
      // 取出一个元素
      node = queue.front();
      queue.pop();

      // 左右放入队列, 下一层每次+1
      if (node->left) {
        queue.push(node->left);
        nextLevelSize++;
      }
      if (node->right) {
        queue.push(node->right);
        nextLevelSize++;
      }

      // 当前存入结果集
      arr.emplace_back(node->val);
      // 到了当前层的最后
      if (--currSize == 0) {
        currSize = nextLevelSize;  // 下一层变为当前层
        nextLevelSize = 0;         // 下一层从零开始
        res.push_back(arr);        // 数组传给结果集
        arr.clear();               // 数组清空
      }
    }
    return res;
  }

  // 最大深度, 递归
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
  }

  // 是否是中心对称的, 递归
  bool isSymmetric(TreeNode* root) {
    // 左右子树相等
    // 都不存在
    // 该节点不存在
    if (!root || !(root->left || root->right)) {
      return true;
    } else if ((root->left && root->right &&
                root->right->val == root->right->val)) {
      return isSymmetric(root->left) && isSymmetric(root->right);
    } else {
      return false;
    }
  }

  // 是否有给定的路径总和
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      // 表示进入了为空的子节点, 没有走到叶节点
      return false;
    } else if (!root->left && !root->right) {
      // 叶子节点返回是否刚好等于sum
      return root->val == sum;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }

  // 是否左右对称
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return isSymmetricHelper(root->left, root->right);
  }

  // 是否左右对称的帮助函数
  bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    // 有一个不存在就返回 false
    // 两个不存在就返回true
    if (!left || !right) {
      return left == right;
    }

    // 值不相等, 返回false
    if (left->val != right->val) {
      return false;
    }

    return isSymmetricHelper(left->left, right->right) &&
           isSymmetricHelper(left->right, right->left);
  }

  // 是否左右对称的 iter 版本
  bool isSymetricIter(TreeNode* root) {
    if (!root) return true;
    stack<TreeNode*> check;
    check.push(root->left);
    check.push(root->right);

    TreeNode *n1, *n2;
    while (!check.empty()) {
      n1 = check.top();
      check.pop();
      n2 = check.top();
      check.pop();

      // 都为空, 则继续
      if (!n1 && !n2) {
        continue;
      }
      // 只有一个为空, 或者 值不相等
      // 表示不对称, 返回false
      if (!n1 || !n2 || n1->val != n2->val) {
        return false;
      }

      // 按照顺序塞入stack中
      check.push(n1->left);
      check.push(n2->right);
      check.push(n1->right);
      check.push(n2->left);
    }
    return true;
  }

  // 根据inorder 和postorder 建树
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {}
};

int main(int argc, char const* argv[]) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(3);
  Solution s{};
  // vector<vector<int>> res = s.levelOrder(root);
  // for (auto arr : res) {
  //   for (auto num : arr) {
  //     cout << num << " ";
  //   }
  // }

  bool isSymmeRes = s.isSymmetric(root);
  assert(!isSymmeRes);
  bool hasPath = s.hasPathSum(root, 6);
  assert(hasPath);
  return 0;
}
