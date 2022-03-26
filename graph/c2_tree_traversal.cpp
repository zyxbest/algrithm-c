#include <assert.h>
#include <iostream>
#include <stack>

using namespace std;

const int MaxSize = 7;
int pre[MaxSize], in[MaxSize], post[MaxSize];
int n, i, L, R;
stack<int> s;

void print() {

  for (int i = 0; i < MaxSize; i++) {
    cout << pre[i] << " ";
  }

  cout << "\n";
  for (int i = 0; i < MaxSize; i++) {
    cout << in[i] << " ";
  }

  cout << "\n";
  for (int i = 0; i < MaxSize; i++) {
    cout << post[i] << " ";
  }

  // cout << pre ;
  // cout << in;
}

void input() {
  cin >> n;
  string str;
  int i = 0, j = 0, data;
  for (int k = 0; k < 2 * n; k++) {
    cin >> str;
    if (str == "Push") {
      cin >> data;
      s.push(data);
      pre[i++] = data;

    } else {
      in[j++] = s.top();
      s.pop();
    }
  }
}

void solve(int preL, int inL, int postL, int n) {
  if (n == 0) {
    return;
  }
  if (n == 1) {
    post[postL] = pre[preL];
    return;
  }

  int root = pre[preL];
  post[postL + n - 1] = root;
  for (i = 0; i < n; i++)
    if (in[preL + i] == root)
      break;

  L = i;
  R = n - L - 1;
  solve(preL + 1, inL, postL, L);
  solve(preL + L + 1, inL + L + 1, postL + L, R);
}

int main(int argc, char const *argv[]) {
  input();
  solve(0, 0, 0, n);
  print();
  return 0;
}
