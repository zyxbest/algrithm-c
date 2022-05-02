#include <iostream>
class A {
 private:
  //  declare
  static int mem;

 public:
  static int getMem() { return mem; }
};

// define
int A::mem{1};

class IdGenerator {
  // declaration
 private:
  static int nextID;

 public:
  static int getID();
};
// definition
int IdGenerator::nextID{1};
int IdGenerator::getID() { return nextID++; }

int main(int argc, char const* argv[]) {
  // A::mem = 3;
  std::cout << A::getMem() << std::endl;

  for (int i = 0; i < 5; i++) {
    std::cout << IdGenerator::getID() << " ";
  }

  return 0;
}
