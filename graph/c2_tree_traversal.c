#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int pre[] = {1, 2, 3, 4, 5, 6};
int in[] = {3, 2, 4, 1, 6, 5};
int post[] = {0, 0, 0, 0, 0, 0};
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
  int i = 0;
  for (in[i] != root; i < n; i++) {
  }
  solve(preL + 1, inL, postL, i);
  solve(preL + i + 1, inL + i + 1, postL + i, n - i - 1);
}

int main(int argc, char const *argv[]) {
  solve(0, 0, 0, 6);
  return 0;
}
