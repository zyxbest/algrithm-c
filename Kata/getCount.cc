#include <iostream>
#include <string>
using namespace std;

int getCount(const string &inputStr) {
  int num_vowels = 0;
  // your code here
  for (char c : inputStr) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      num_vowels++;
    }
  }
  return num_vowels;
}

int main(int argc, char const *argv[]) {
  cout << getCount("aiif");
  return 0;
}
