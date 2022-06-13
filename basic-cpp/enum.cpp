#include <iostream>
using namespace std;
enum week {
  m,
  s,
  w,
  t,
  f,
  sun,
};

enum { UNVISITED = -1, RED, YELLOW };

int main(int argc, char const *argv[]) {
  week a = m;
  cout << a << " " << a + 1 << endl;
  cout << UNVISITED << " " << RED << " " << YELLOW;

  return 0;
}
