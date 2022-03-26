#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.push(a);
  }

  while (!s.empty()) {
    int top = s.top();
    cout << top << " ";
    s.pop();
  }

  return 0;
}
