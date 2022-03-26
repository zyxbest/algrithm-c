#include<iostream>
#include<string>

using namespace std;
int main(int argc, char const *argv[])
{

  string str = "sfdadf";
  string s =str;
  s[0] = '1';
  cout << s;
  return 0;
}
