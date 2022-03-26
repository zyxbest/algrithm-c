#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> subs(string s);
void process(string s, int i, set<string> &set, string path);

set<string> subs(string s) {
  set<string> myset;

  string path = "";
  process(s, 0, myset, path);
  return myset;
}

/**
 * @brief 递归求所有的子字串
 *
 * @param s 原字串
 * @param i index
 * @param set 不重复的集合
 * @param path 过程中的子字串
 */
void process(string s, int i, set<string> &set, string path) {
  if (i == s.length()) {
    set.insert(path);
    return;
  }

  process(s, i + 1, set, path);
  process(s, i + 1, set, path + s.at(i));
}

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  cout << "s.length is" << s.length() << "\n";
  set<string> myset = subs(s);
  cout << myset.size() << "\n";
  //   for_each(myset.begin(), myset.end(), [](string x) { cout << x << ","; });
  return 0;
}
