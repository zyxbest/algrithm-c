#include <bits/stdc++.h>
using namespace std;

#define MaxSize 1000
typedef int ElementType;  // 数据类型
// 并查集结构体定义
struct SetType {
  ElementType data;
  int parent;
};

class UnionFindSet {
 private:
  SetType s[MaxSize];

 public:
  UnionFindSet() {
    for (int i = 0; i < MaxSize; i++) {
      s[i].data = i + 1;
      s[i].parent = -1;
    }
  }
  int find(ElementType x) {
    int i = 0;
    // 找到数组的该值对应的下标
    while (s[i].data != x && i++ < MaxSize)
      ;
    if (i == MaxSize) {
      return -1;
    }

    // 找到下标的根节点
    while (s[i].parent >= 0) {
      i = s[i].parent;
    }
    return i;
  }

  void unionSet(ElementType x1, ElementType x2) {
    int root1 = find(x1);
    int root2 = find(x2);

    // 不是一个集合
    if (root1 != root2) {
      // 自挂另一个根节点下
      s[root1].parent = root2;
    }
  }
};

int main(int argc, char const* argv[]) {
  UnionFindSet* set = new UnionFindSet();
  cout << set->find(4) << endl;

  set->unionSet(3, 4);
  cout << set->find(3) << endl;
  cout << set->find(4) << endl;

  set->unionSet(1, 3);
  set->unionSet(8, 6);
  cout << set->find(6) << " " << set->find(8) << endl;
  return 0;
}
