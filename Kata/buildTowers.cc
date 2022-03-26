#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> towerBuilder(unsigned nFloors) {
  vector<string> arr;
  int len = 2 * nFloors - 1; // 固定长度
  for (int i = 0; i < nFloors; i++) {
    string s(len, ' '); // 初始化为固定长度的空字符串
    for (int j = 0; j < 2 * i + 1; j++) {
      s[nFloors - 1 - i + j] = '*'; // 主要逻辑
    }

    arr.push_back(s);
  }
  return arr;
}

int main(int argc, char const *argv[]) {

  cout << 12%10;
  vector<string> arr = towerBuilder(13);
  for (string s : arr) {
    cout << s << "\n";
  }
  return 0;
}
