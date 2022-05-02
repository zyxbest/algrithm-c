#include <iostream>
using namespace std;
class Test {
 private:
  int priMem;

 public:
  int a;

  void setPriMem(int mem);
  int getPriMem();
};
void Test::setPriMem(int mem) { this->priMem = mem; };
int Test::getPriMem() { return priMem; }

int main(int argc, char const *argv[]) {
  Test t{};
  cout << t.getPriMem() << " " << t.a;
  return 0;
}
