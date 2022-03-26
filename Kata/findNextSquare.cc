
#include <ctype.h>
#include <iostream>
#include <math.h>
using namespace std;
long int findNextSquare(long int sq) {
  // Return the next square if sq if a perfect square, -1 otherwise
  double d = sqrt(sq);
  if (d != (int)d) {
    return -1;
  }

  // d+1 * d+1
  return ++d * d;
}

int main(int argc, char const *argv[]) {
  cout << findNextSquare(1001);
  return 0;
}
