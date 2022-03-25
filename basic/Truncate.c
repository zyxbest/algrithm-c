#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 复制字串
char *strdupa(char *str) {
  size_t len = strlen(str);
  char *dup = malloc(sizeof(char) * len);
  memcpy(dup, str, len);
  return dup;
}

// 截取字串
char *truncate(char *str, int n) {
  size_t len = strlen(str);
  if (len > abs(n)) {
    if (n > 0) {
      str = str + n;
    } else {
      str[len + n] = 0;
    }
  }

  return str;
}

// 以char数组的形式打印字串
void printChar(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    printf("%c ", str[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  char *s = {"aeics"};
  printChar(s);
  printChar(strdupa(s));
  printChar(truncate(strdupa(s), 100));
  printChar(truncate(strdupa(s), 2));
  printChar(truncate(strdupa(s), -3));
  return 0;
}
