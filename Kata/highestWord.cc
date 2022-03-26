#include <iostream>
#include <string>
using namespace std;
std::string highestScoringWord(const std::string &str) {

  
  string s, maxs;
  int num = 0, max = 0;
  for (char c : str) {
    if (c != ' ') {
      s += c;
      num += c - 96;
    } else {
      if (s != "" || max == 0) {
        if (num > max) {
          max = num;
          maxs = s;
        }
        num = 0;
        s = "";
      }
    }
  }
  if (num > max) {
    max = num;
    maxs = s;
  }
  return maxs;
}

int main(int argc, char const *argv[]) {
  cout << highestScoringWord("man i need a taxi up to ubud") << "\n";
  cout << highestScoringWord("what time are we climbing up the volcano");
  return 0;
}
