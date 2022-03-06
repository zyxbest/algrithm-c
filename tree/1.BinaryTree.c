#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode, *BinTree;

// https://www.bilibili.com/video/BV1JW411i731?p=34&spm_id_from=pageDriver
BinTree insert(int data);            // 插入一颗二叉树
void traversalRecursion(BinTree bt); // 遍历（非递归）

typedef struct Node {
  BinTree data;
  struct Node *next;
} Node, *Stack;

Stack createStack() {
  Stack s = (Stack)malloc(sizeof(Node));
  s->next = NULL;
  return s;
}

void push(Stack s, BinTree bt) {
  Stack temp = (Stack)malloc(sizeof(Node));
  temp->data = bt;
  temp->next = s->next;
  s->next = temp;
}

BinTree pop(Stack s){
    
}

BinTree createBinaryTree() {
  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = 1;
  bt->left = insert(2);
  bt->right = insert(3);
  return bt;
}

BinTree insert(int data) {
  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = data;
  bt->left = NULL;
  bt->right = NULL;
  return bt;
}
// 先序遍历（非递归）
void traversalRecursion(BinTree bt) {
  if (bt) {
    traversalRecursion(bt->left);
    traversalRecursion(bt->right);
    printf("%d ", bt->data);
  }
}

void inTraversal(BinTree bt) {}

int main(int argc, char const *argv[]) {
  BinTree bt = createBinaryTree();
  traversalRecursion(bt);
  return 0;
}
