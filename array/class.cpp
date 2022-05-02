#include <iostream>
#include <string>
using namespace std;

class AbstractEmployee {
  virtual void askForPromotion() = 0;
};

class Employee : public AbstractEmployee {
  // 默认是private的
 public:
  string name;
  string company;
  int age;

  Employee(string name, string company, int age) {
    this->name = name;
    this->company = company;
    this->age = age;
  }

  void askForPromotion() {
    if (age > 30) {
      cout << name << " got promoted!" << endl;
    } else {
      cout << name << ", sorry no promotion for you ! " << endl;
    }
  }
};
class Teacher : Employee {
 public:
  string subject;
  void prepareLesson() {
    cout << name << endl;
    askForPromotion();
  }

  Teacher(string name, string company, int age, string subject)
      : Employee(name, company, age) {
        this->subject = subject;
      }
};

int main(int argc, char const *argv[]) {
  Employee employee1 = Employee("zyx", "wistron", 25);
  cout << employee1.age << endl;
  employee1.askForPromotion();

  Teacher t;
  return 0;
}
