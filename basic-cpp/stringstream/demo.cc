#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  // Complete this function
  vector<int> arr;
  stringstream ss(str);
  char ch;
  int num;
  while (ss) {
    ss >> num >> ch;
    arr.push_back(num);
  }

  return arr;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}