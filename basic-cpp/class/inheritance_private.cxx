#include <iostream>
#include <string>
using namespace std;

class Base {
 private:
  int m_id{};

 public:
  Base(int id = 0) : m_id(id) {}
  int getId() { return m_id; }
};

class Derived : public Base {
 private:
  double m_cost;

 public:
  Derived(double cost = 0.0, int id = 0) : Base(id), m_cost(cost) {}
  double getCost() { return m_cost; }
};

int main(int argc, char const* argv[]) {
  Derived p{1.3, 12};
  cout << p.getId() << " " << p.getCost() << '\n';

  return 0;
}
