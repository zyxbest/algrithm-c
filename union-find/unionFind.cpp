#include <bits/stdc++.h>
using namespace std;
struct Node {
  int v;
  Node(int v) : v(v){};
};

class UnionFindSet {
 private:
  map<int, Node*> nodes;    // 数字对应的node
  map<Node*, Node*> heads;  // node的头结点
  map<Node*, int> sizes;    // node 所在的集合大小

 public:
  UnionFindSet(list<int> values);
  // 合并两个集合
  void unionSet(int v1, int v2);
  // 找到头结点
  Node* findHead(Node* node);
  // 判断两个点是否连通
  bool connected(int x, int y);
};

UnionFindSet::UnionFindSet(list<int> values) {
  for (auto v : values) {
    Node* node = new Node(v);
    nodes[v] = node;     // 数字对应对象
    heads[node] = node;  // 顶点是自己
    sizes[node] = 1;     // 初始化为1, 只有自己
  }
}

void UnionFindSet::unionSet(int v1, int v2) {
  Node* head1 = findHead(nodes[v1]);  // size 较小的node 的head
  Node* head2 = findHead(nodes[v2]);  // size较大
  // 根节点不相等
  if (head1->v != head2->v) {
    // 如果head1 size较大, 就交换
    if (sizes[head1] > sizes[head2]) {
      Node* head = head2;
      head2 = head1;
      head1 = head;
    }
    heads[head1] = head2;
    sizes[head2] = sizes[head1] + sizes[head2];

    // 较小的size删除
    sizes.erase(head1);
  }
}

/* Node* UnionFindSet::findHead(Node* node) {
  list<Node*> arr;

  // 找到顶点
  while (node->v != heads[node]->v) {
    arr.push_back(node);
    node = heads[node];
  }

  // 将沿途的顶点都设为node
  for (auto item : arr) {
    heads[item] = node;
  }
  return node;
} */

// 递归找到头
Node* UnionFindSet::findHead(Node* node) {
  if (node == heads[node]) {
    return node;
  }
  // 绝了, 返回的时候, 同时赋值, 优雅
  return node = findHead(heads[node]);
}

bool UnionFindSet::connected(int x, int y) {
  return findHead(nodes[x])->v == findHead(nodes[y])->v;
}

int main(int argc, char const* argv[]) {
  UnionFindSet* unionFindSet = new UnionFindSet({2, 34, 12, 3, 4});
  assert(!unionFindSet->connected(2, 3));
  unionFindSet->unionSet(2, 3);
  assert(unionFindSet->connected(2, 3));
  assert(!unionFindSet->connected(4, 3));
  return 0;
}
