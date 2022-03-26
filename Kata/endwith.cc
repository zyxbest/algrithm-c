#include <string>

using namespace std;
bool solution(std::string const &str, std::string const &ending) {
  return string(str.end() - str.size(), str.end()) == ending;
  
}

