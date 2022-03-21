#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int pre[] = {1, 2, 3, 4, 5, 6};
int in[] = {3, 2, 4, 1, 6, 5};
int post[7];
void solve(int preL, int inL, int postL, int n) {
  int root = pre[preL];
  post[postL + n - 1] = root;
  
}

int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
