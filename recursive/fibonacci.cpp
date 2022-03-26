#include <cassert>
#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

void test() {
  assert(fibonacci(10) == 55);

  assert(fibonacci(1) == 1);
  cout << "All test passed!";
}


int main(int argc, char const *argv[]) {
  test();
  return 0;
}
