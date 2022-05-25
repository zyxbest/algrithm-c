#include <bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[], int f[], int n) {
  int i = 0;
  cout << " " << i;
  for (int j = 1; j < n; j++) {
    // 开始时间在上一次的结束时间之后
    if (s[j] >= f[i]) {
      i = j;
      cout << " " << j;
    }
  }
}

int main(int argc, char const *argv[]) {
  int s[] = {1, 3, 0, 5, 8, 5};
  int f[] = {2, 4, 6, 7, 9, 9};
  int n = sizeof(s) / sizeof(s[0]);
  printMaxActivities(s, f, n);
  return 0;
}
