#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
using namespace std;
auto print = [](string x) { cout << x << " "; };

set<string> create() {
  set<string> se;
  se.insert("nihao");
  se.insert("fs");
  return se;
}

char *createChar() {
  char *a = (char *)malloc(sizeof(char) * 10);
  a[0] = '1';
  return a;
}

// 传一个 set对象到参数 的时候，一定要传指针
void remove(set<string> &a) { a.erase("fs"); }

void testA() {
  set<string> se = create();
  remove(se);
  for_each(se.begin(), se.end(), print);
}

void testCreateChar() {
  char *a = createChar();
  cout << a[0];
}

int main(int argc, char const *argv[]) {
  testA();
  testCreateChar();
  return 0;
}
