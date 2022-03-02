#include "code03_LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  LStack s = createStack();
  char str[100];
  scanf("%99s", &str);
  printf("%s", str);
  int i = 0;
  while (i < strlen(str)) {
    printf("%c ", str[i++]);
  }

  //   s->next
  return 0;
}
