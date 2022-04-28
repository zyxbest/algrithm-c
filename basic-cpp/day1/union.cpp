#include <iostream>
using namespace std;
union my {
  struct {
    int x, y, z;
  } u;
  int k;
} u;

int main(int argc, char const *argv[]) {
  u.u.x = 1;
  u.u.y = 2;
  u.u.z = 3;
  u.k = 4;
  cout << u.u.x << " " << u.u.y << u.u.z << u.k << endl;
  system("pause");
  return 0;
}
