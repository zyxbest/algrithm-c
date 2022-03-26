#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LongestConsec {
public:
  static std::string longestConsec(std::vector<std::string> &strarr, int k) {
    string result = "";
    string temp = "";
    for (int i = 0; i < strarr.size() - k + 1; i++) {
      temp = ""; // 清空

      // 将k个单词拼接
      for (int j = i; j < i + k; j++) {
        temp += strarr[j];
      }

      // 如果长度比之前的大的话就替换
      if (result.size() < temp.size()) {
        result = temp;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<string> arr = {"zone", "abigail", "theta", "form",
                        "libe", "zas",     "theta", "abigail"};
  cout << LongestConsec::longestConsec(arr, 2);
  return 0;
}
