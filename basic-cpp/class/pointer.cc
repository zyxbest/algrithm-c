#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int x{5};
  cout << x << endl;
  cout << &x << endl;     // address
  cout << *(&x) << endl;  // deference
  return 0;
}
