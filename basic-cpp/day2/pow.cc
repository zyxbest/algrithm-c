#include <cassert>
#include <iostream>
using namespace std;

double pow(double x, int n) {
  double result = 1;
  while (n--) {
    result *= x;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  assert(pow(3, 2) == 9);
  assert(pow(2, 21) == (1<<21));
  return 0;
}
