#include <iostream>
using namespace std;

// n的阶乘
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int recursive(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * recursive(n - 1);
  }
}
int main(int argc, char const *argv[]) {
  cout << factorial(5) << "\n";
  cout << recursive(5);
  return 0;
}
