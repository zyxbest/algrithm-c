#include <bitset>
#include <iostream>
#include <string>
using namespace std;
std::string uint32_to_ip(uint32_t ip) {
  // your code here
  string result;
  string s = bitset<32>(ip).to_string();
  for (size_t i = 0; i < 32; i += 8) {

    result.append(to_string(stoi(s.substr(i, 8), 0, 2)).append("."));
  }

  result.erase(result.length() - 1);
  return result;
}

int main(int argc, char const *argv[]) {
  cout << uint32_to_ip(2154959208);
  return 0;
}
