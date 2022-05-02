#include <array>
#include <iostream>
using namespace std;
// initiallizer list
class A {
 public:
  int val1{};
  double val2{};
  char val3{};
  float val4{};

 public:
  A(int val1, double val2, char val3 = 'c', float val4 = 3.42f)
      : val1{val1}, val2{val2}, val3{val3}, val4{val4} {}
};

int main(int argc, char const *argv[]) {
  A a{1, 1.2};
  cout << a.val1 << a.val2 << a.val3 << a.val4 << endl;
  return 0;
}
