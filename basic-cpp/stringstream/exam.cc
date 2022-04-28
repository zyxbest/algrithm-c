/* htrm analysis */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, q;
  cin >> n >> q;

  string s;
  string temp, key, value;
  for (int i = 0; i < n / 2; i++) {
    cin >> s;
    int count = 0;
    for (int j = 1; j < s.size(); j++) {
      char ch = s[j];
      if (ch != ' ' || ch != '>') {
        temp += ch;
      } else if (ch == '=') {
      }
    }
  }
  return 0;
}
