#include <iostream>
int main(int argc, char const* argv[]) {
  int x{5};
  // lvalue reference , 可以说和原值一模一样, 只是一个别名
  // 引用绑定 , ref是引用,  x 是 参照 , 只能绑定 可修改左值
  int& ref{x};

  const int y{1};
  // int& invalidRef{0};
  // int& invalidRef{y};
  std::cout << x << " " << ref << std::endl;

  // 修改引用会修改 引用的对象
  x = 6;
  std::cout << x << " " << ref << std::endl;

  ref = 7;
  std::cout << x << " " << ref << std::endl;

  int z{5};
  ref = z;
  return 0;
}
