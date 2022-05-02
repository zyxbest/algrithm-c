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
int main(int argc, char const *argv[]) {
  week a = m;
  cout << a << " " << a + 1;

  return 0;
}
