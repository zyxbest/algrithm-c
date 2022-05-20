#include <iostream>
// 传递的是x的copy,不是真实的x
void addOne(int y) { ++y; }

// 对引用的任何改变都会影响到参数
void addOneByReference(int& y) { ++y; }

// 不允许的操作 
// void addOneByReference(const int& y) { ++y; }

int main(int argc, char const* argv[]) {
  int x{5};
  std::cout << x << std::endl;
  addOne(x);
  std::cout << x << std::endl;
  addOneByReference(x);

  // addOneByReference(5); 必须要传一个可修改的值
  std::cout << x << std::endl;

  return 0;
}
