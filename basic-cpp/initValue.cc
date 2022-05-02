#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  // brace initialization
  // 会进行类型检查
  // error: narrowing conversion of '4.5e+0' from 'double' to 'int'
  // int a{4.5};

  int a{4};
  // value初始化,零初始化
  int b{};

  string s{"hello, world!"};

  vector<int> arr{1, 2, 3};
  cout << b << " " << s << " " << arr.size() << endl;
  return 0;
};