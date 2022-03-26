#include <iostream>
int digital_root(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  std::cout << digital_root(16);
  return 0;
}
