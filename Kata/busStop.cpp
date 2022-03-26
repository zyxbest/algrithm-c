using namespace std;
#include <iostream>
#include <utility>
#include <vector>
unsigned int number(const std::vector<std::pair<int, int>> &busStops) {
  // your code here
  int n = 0;
  for (auto &[up, down] : busStops) {
    cout << up << "  " << down << "\n";
    n = n + up - down;
  }
  return n;
}

using V = std::pair<int, int>;
using V2 = std::vector<V>;

int main(int argc, char const *argv[]) {
  cout << (int)'a' -96 << '\n';
  cout << number(V2{V{10, 0}, V{3, 5}, V{5, 8}});
  return 0;
}

/* Describe(Number){
  It(BasicTests){
    Assert::That(number(V2{V{10,0},V{3,5},V{5,8}}), Equals(5));
    Assert::That(number(V2{V{3,0},V{9,1},V{4,10},V{12,2},V{6,1},V{7,10}}),
Equals(17));
    Assert::That(number(V2{V{3,0},V{9,1},V{4,8},V{12,2},V{6,1},V{7,8}}),
Equals(21)); Assert::That(number(V2{V{0,0}}), Equals(0));
    Assert::That(number(V2{V{10,0},V{13,0},V{17,40}}), Equals(0));
  }
}; */