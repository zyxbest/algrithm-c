#if !defined(LE_COMMON)
#define LE_COMMON

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){};
  
};

#endif  // LE_COMMON
