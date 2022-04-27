#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode TreeNode, *BinTree;
struct TreeNode {
  int data;
  BinTree left;
  BinTree right;
};

// https://www.bilibili.com/video/BV1JW411i731?p=34&spm_id_from=pageDriver
BinTree insert(int data);            // 插入一颗二叉树
void traversalRecursion(BinTree bt); // 遍历（递归）

typedef struct Node Node, *Stack;
struct Node {
  BinTree data;
  Stack next;
};

Stack createStack();            // 创建具有头结点的stack
BinTree pop(Stack s);           // 出栈
void push(Stack s, BinTree bt); // 入栈
int isStackEmpty(Stack s);      // 判空

// 创建具有头结点的stack
Stack createStack() {
  Stack s = (Stack)malloc(sizeof(Node));
  s->next = NULL;
  return s;
}

// 入栈
void push(Stack s, BinTree bt) {
  Stack temp = (Stack)malloc(sizeof(Node));
  temp->data = bt;
  temp->next = s->next;
  s->next = temp;
}
// 出栈
BinTree pop(Stack s) {
  if (isStackEmpty(s)) {
    printf("stack empty!\n");
    exit(1);
  }

  Node *temp = s->next;
  s->next = temp->next;
  return temp->data;
}
// 判空
int isStackEmpty(Stack s) { return s->next == NULL; }

/******链表队列********/
typedef struct QueueNode {
  BinTree tree;
  struct QueueNode *next;
} QueueNode;

typedef struct QNode {
  QueueNode *front;
  QueueNode *rear;
} QNode, *Queue;

// 创建queue
Queue createQueue() {
  Queue q = (Queue)malloc(sizeof(QNode));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

int isEmptyQ(Queue q) { return q->front == NULL; }

void addQ(Queue q, BinTree bt) {
  QueueNode *qNode = (QueueNode *)malloc(sizeof(QueueNode));
  qNode->tree = bt;
  qNode->next = NULL;

  if (isEmptyQ(q)) {
    q->front = qNode;
  } else {
    q->rear->next = qNode;
  }
  q->rear = qNode;
}

TreeNode *delQ(Queue q) {
  if (isEmptyQ(q)) {
    printf("queue empty!");
    exit(1);
  }

  QueueNode *first = q->front;
  BinTree bt = first->tree;
  q->front = first->next;
  free(first);
  return bt;
}

/******二叉树函数定义处 *******/

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
// 先序遍历（递归）
void traversalRecursion(BinTree bt) {
  if (bt) {
    printf("%d ", bt->data);
    traversalRecursion(bt->left);
    traversalRecursion(bt->right);
  }
}

// 中序遍历
void inTraversal(BinTree bt) {
  BinTree t = bt;
  Stack s = createStack();
  // 或者采用下面的写法
  // Stack s = (Stack)malloc(sizeof(Node));
  // s->next = NULL;
  while (t || !isStackEmpty(s)) {
    while (t) {
      push(s, t);
      t = t->left;
    }
    if (!isStackEmpty(s)) {
      t = pop(s);
      printf("%5d", t->data);
      t = t->right;
    }
  }
}

// 前序遍历
void beforeTraversal(BinTree bt) {
  BinTree t = bt;
  Stack s = createStack();
  while (t || !isStackEmpty(s)) {
    while (t) {
      printf("%5d", t->data);
      push(s, t);
      t = t->left;
    }

    if (!isStackEmpty(s)) {
      t = pop(s);
      t = t->right;
    }
  }
}

// 后序遍历
// 跟弹出，放入 栈B 左右放入栈A
void afterTraversal(BinTree bt) {
  Stack stack = createStack();
  Stack result = createStack();

  push(stack, bt);

  while (!isStackEmpty(stack)) {
    bt = pop(stack);
    push(result, bt);
    if (bt->left) {
      push(stack, bt->left);
    }
    if (bt->left) {
      push(stack, bt->right);
    }
  }
  BinTree node;
  while (!isStackEmpty(result)) {
    node = pop(result);
    printf("%5d", node->data);
  }
}

// 层序遍历
void levelTraversal(BinTree bt) {
  BinTree t = bt;
  Queue q = createQueue();
  addQ(q, t);

  while (!isEmptyQ(q)) {
    t = delQ(q);
    printf("%5d", t->data);
    if (t->left) {
      addQ(q, t->left);
    }
    if (t->right) {
      addQ(q, t->right);
    }
    // 解决bug，是因为 内存被删掉了， 导致原来的数据不正常了，所以删除指针的
    // 空间要谨慎
    // free(t);
  }
  free(q);
}

void getLeaves(BinTree bt) {
  if (bt) {
    if (!bt->left && !bt->right) {
      printf("%d ", bt->data);
    }
    getLeaves(bt->left);
    getLeaves(bt->right);
  }
}

// 求树的高度
int postOrderGetHeight(BinTree bt) {
  BinTree t = bt;
  int left, right, max;
  if (t) {
    left = postOrderGetHeight(t->left);
    right = postOrderGetHeight(t->right);
    max = (left > right) ? left : right;
    return max + 1;
  } else {
    return 0;
  }
}
void testStack() {
  Stack s = createStack();
  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = 1;

  bt->left = insert(2);
  bt->right = insert(4);
  push(s, bt);
  push(s, bt->left);
  push(s, bt->right);
  TreeNode *t = pop(s);
  printf("pop(s)->data %d\n", t->data);
  pop(s);
  pop(s);
  assert(t->data == 4);
  assert(isStackEmpty(s));
}

void testQ() {

  BinTree bt = (BinTree)malloc(sizeof(TreeNode));
  bt->data = 1;

  bt->left = insert(2);
  bt->right = insert(3);
  Queue q = createQueue();
  assert(isEmptyQ(q) == 1);
  addQ(q, bt);
  addQ(q, bt->left);
  addQ(q, bt->right);
  BinTree node = delQ(q);
  printf("node->tree->data %d\n", node->data);
  assert(node->data == 1);

  node = delQ(q);
  printf("node->tree->data %d\n", node->data);
  assert(node->data == 2);

  free(node);
  free(bt);
  free(q);
}

int main(int argc, char const *argv[]) {
  BinTree bt = createBinaryTree();
  traversalRecursion(bt);
  testStack();
  testQ();
  printf("前序遍历");
  beforeTraversal(bt);
  printf("\n中序遍历");
  inTraversal(bt);
  printf("\n后续遍历");
  afterTraversal(bt);
  printf("\n层序遍历");
  levelTraversal(bt);
  printf("\n最大高度为 %d", postOrderGetHeight(bt));
  printf("\nleaves are ");
  getLeaves(bt);
  return 0;
}
