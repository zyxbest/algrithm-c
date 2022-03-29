#include <string>
#include <vector>

using namespace std;
vector<string> solution(const string &s) {

  vector<string> arr;
  for (size_t i = 0; i < s.size(); i += 2) {
    string str = {s[i]};
    if (i == s.size() - 1) {
      str += '_';
    } else {
      str.push_back(s[i + 1]);
    }
    arr.push_back(s);
  }
  return arr; // Your code here
}