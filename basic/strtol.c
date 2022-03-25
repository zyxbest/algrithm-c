#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 字符串 转为 整数
int main(int argc, char const *argv[]) {
  char *s = "234";
  printf("%ld\n", strtol(s, NULL, 10));
  printf("%d\n", atoi(s));

  char *cp;
  strcpy(cp, s);

  printf("%d\n", strtol(cp, NULL, 10));

  return 0;
}
