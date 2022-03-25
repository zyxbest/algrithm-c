#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *str1;

  int n;

  str1 = (char *)malloc(sizeof(char) * 10);
  scanf("%7s", str1);
  printf("%s\n", str1);
  return 0;
}
