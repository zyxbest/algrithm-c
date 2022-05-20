#include <iostream>
#include <string>
using namespace std;

class Person {
 public:
  string m_name{};
  int m_age{};

  Person(const string& name = "", int age = 0) : m_name{name}, m_age{age} {
    cout << "constructor of Person!" << endl;
  };
  string getName() { return m_name; }
  int getAge() { return m_age; }
};

// public inheritance
class BaseBallPlayer : public Person {
 public:
  double m_battingAverage{};
  int m_homeRuns{};

  BaseBallPlayer() {}

  BaseBallPlayer(double battingAverage = 0.0, int homeRuns = 0)
      : m_battingAverage{battingAverage}, m_homeRuns{homeRuns} {
    cout << "constructor of BaseBallPlayer!" << endl;
  }

  BaseBallPlayer(double battingAverage = 0.0, int homeRuns = 0, int age = 0,
                 const string& name = "")
      : Person{name, age},
        m_battingAverage{battingAverage},
        m_homeRuns{homeRuns} {}
};

int main(int argc, char const* argv[]) {
  BaseBallPlayer p{12, 2, 12, "nihao"};
  // p.m_name = "joe";
  cout << p.getName() << '\n';

  return 0;
}
