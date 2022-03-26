#include <algorithm>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

string best(string &word) {
  map<char, int> table;
  for (char c : word) {
    table[tolower(c)]++;
  }

  string result;
  for (char c : word) {
    result += table[tolower(c)] > 1 ? ')' : '(';
  }

  return result;
}

string duplicateEncoder(string str) {

  map<char, vector<int>> m;
  transform(str.begin(), str.end(), str.begin(),
            [](unsigned char c) { return tolower(c); });
  for (size_t i = 0; i < str.length(); i++) {
    if (m.count(str[i])) {
    } else {
      m[str[i]] = vector<int>();
    }
    m[str[i]].push_back(i);
  }
  string s = str;

  for (auto &[key, values] : m) {
    if (values.size() > 1) {
      for (size_t i = 0; i < values.size(); i++) {
        s[values[i]] = ')';
      }

    } else {
      s[values[0]] = '(';
    }
  }
  return s;
}
string DuplicateEncoder(string str) {
  // TODO : Your code.
  string res;
  for (size_t i = 0; i < str.length(); i++) {
    int locate = res.find(str[i]);
    if (locate) {
      res[locate] = str[locate];
    } else {
      // 没找到就直接拼接
      res.push_back(str[i]);
    }
    // char *find = strchr(str, str[i]);
    // printf("%p ", find);
    // if (find) {
    //   res[i] = ')';
    // } else {
    //   res[i] = '(';
    // }
  }
  return res;
}

char *testTemp(char *str) {
  char *res = (char *)calloc(strlen(str), sizeof(char));
  cout << &str << "df";
  cout << strchr(str, 'r') << "heello";
  return res;
}

int main(int argc, char const *argv[]) {
  string str = "rEcede";
  cout << duplicateEncoder(str) << '\n';
  cout << best(str);

  // printf("%s", testTemp("if"));
  return 0;
}
