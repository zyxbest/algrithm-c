#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode, *BinTree;

BinTree insertBST(BinTree bst, int x);
BinTree deleteBST(BinTree bst, int x);

BinTree insert(int data) {
  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = data;
  bt->left = NULL;
  bt->right = NULL;
  return bt;
}

BinTree createTree() {
  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = 1;
  bt->left = insert(2);
  bt->right = insert(3);

  bt->left->left = insert(4);
  bt->left->right = insert(5);

  bt->right->left = insert(6);
  bt->right->right = insert(7);
  return bt;
}

BinTree createBST() {
  BinTree bst = NULL;
  bst = insertBST(bst, 6);
  bst = insertBST(bst, 3);
  bst = insertBST(bst, 9);
  bst = insertBST(bst, 1);
  bst = insertBST(bst, 5);
  bst = insertBST(bst, 7);
  bst = insertBST(bst, 20);
  return bst;
}

// 是否是二叉查找树
int isBST(BinTree bt) {
  if (bt->data >= bt->right->data || bt->data <= bt->left->data) {
    return 0;
  }

  isBST(bt->left);
  isBST(bt->right);
}

// 递归实现查找
BinTree find(BinTree bt, int x) {
  if (!bt) {
    return NULL;
  }

  if (x < bt->data) {
    find(bt->left, x);
  } else if (x > bt->data) {
    find(bt->right, x);
  } else {
    return bt;
  }
}

// 查找非递归实现
BinTree findNoRecursive(BinTree bst, int x) {
  while (bst) {
    if (x > bst->data) {
      bst = bst->right;
    } else if (x < bst->data) {
      bst = bst->left;
    } else {
      return bst;
    }
  }
  return NULL;
}

// 递归实现 搜索二叉树找最小值
BinTree findMin(BinTree bst) {
  if (!bst) {
    return NULL;
  } else if (bst->left) {
    return findMin(bst->left);
  } else {
    return bst;
  }
}

// 非递归实现 搜索二叉树 找最小值
BinTree findMinNoRecursive(BinTree bst) {
  if (bst) {
    while (bst->left) {
      bst = bst->left;
    }
  }
  return bst;
}

BinTree findMax(BinTree bst) {
  if (!bst) {
    return NULL;
  } else if (bst->right) {
    return findMax(bst->right);
  } else {
    return bst;
  }
}

BinTree findMaxNoRecursive(BinTree bst) {
  if (bst) {
    while (bst->right) {
      bst = bst->right;
    }
  }
  return bst;
}

BinTree insertBST(BinTree bst, int x) {
  if (!bst) {
    bst = (BinTree)malloc(sizeof(TreeNode));
    bst->data = x;
    bst->left = NULL;
    bst->right = NULL;
  } else {
    if (x > bst->data) {
      bst->right = insertBST(bst->right, x);
    } else if (x < bst->data) {
      bst->left = insertBST(bst->left, x);
    }
  }
  return bst;
}

// 删除
BinTree deleteBST(BinTree bst, int x) {
  BinTree temp;
  // 将有左右子节点的转化为 左右子节点不全的
  if (!bst) {
    printf("该节点不存在\n");
  } else if (x > bst->data) {
    bst->right = deleteBST(bst->right, x);
  } else if (x < bst->data) {
    bst->left = deleteBST(bst->left, x);
  } else {
    if (bst->left && bst->right) {
      temp = findMin(bst->right);
      bst->data = temp->data;
      bst->right = deleteBST(bst->right, temp->data);
    } else {
      temp = bst;
      if (!bst->left) { // 左节点为空
        bst = bst->right;
      } else if (!bst->right) { //  右节点为空
        bst = bst->left;
      }
      free(temp);
    }
  }
  return bst;
}

// 中序递归遍历
void inTraversal(BinTree bst) {
  if (bst) {
    inTraversal(bst->left);
    printf("%5d", bst->data);
    inTraversal(bst->right);
  }
}

int main(int argc, char const *argv[]) {

  BinTree bt = createTree();

  BinTree bst = createBST();

  BinTree node = find(bst, 10); // 没找到为空
  assert(node == NULL);
  node = find(bst, 20);
  assert(node->data == 20); //找到了

  node = findNoRecursive(bst, 10); // 没找到为空
  assert(node == NULL);
  node = findNoRecursive(bst, 20);
  assert(node->data == 20); //找到了

  node = findMin(bst);
  assert(node->data == 1);

  node = findMinNoRecursive(bst);
  assert(node->data == 1);

  node = findMax(bst);
  assert(node->data == 20);

  node = findMaxNoRecursive(bst);
  assert(node->data == 20);

  insertBST(bst, 4);
  inTraversal(bst);

  deleteBST(bst, 4);
  inTraversal(bst);

  return 0;
}
