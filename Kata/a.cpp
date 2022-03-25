#include <cassert>
#include <iostream>
#include <map>
#include <string>
using namespace std;
std::string duplicate_encoder(const std::string &word) {
  string s;
  for (int i = 0; i < word.length(); i++) {
    size_t a = word.find(word[i]);
    s = s + (a == string::npos ? ')' : '(');
  }
  return s;
}

int main(int argc, char const *argv[]) {
  cout << ((1 << 30) - 1) << "\n";

  assert(abs(0) == 0);
  map<char, int> m;
  cout << ((1 << 31)) << "\n";
  int t = abs(0) > ((1 << 31) / 10);
  cout << t;
  string a = duplicate_encoder("recede");
  cout << a;
  return 0;
}
