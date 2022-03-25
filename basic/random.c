#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  srand(time(NULL));
  printf("%d\n", rand());
  perror("hello");
  unsigned int tmp;

  return 0;
}