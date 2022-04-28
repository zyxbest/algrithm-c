#include <iostream>
#include <map>
#include <string>
using namespace std;
void itermap();

int main(int argc, char const *argv[]) {
  string s = "fadsfs";
  for (char item : s) {
    cout << item << '\t';
  }
  itermap();
  return 0;
}

void itermap() {
  map<char, int> m;
  m['a'] = 1;
  m['b'] = 2;

  for (const auto &item : m) {
    cout << item.first << " " << item.second << "\n";
  }

  for (const auto &[key,value] : m) {
    cout << key << " " << value << "\n";
  }
}