#include <iostream>
using namespace std;
// 判断函数
bool isLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

// 打印消息
string yearMesage(int year) {
  return isLeapYear(year) ? "Leap Year" : "Not Leap Year";
}

int main(int argc, char const *argv[]) {
  int year;
  cout << "Enter your year" << endl;
  cin >> year;

  cout << yearMesage(year) << endl;

  return 0;
}
