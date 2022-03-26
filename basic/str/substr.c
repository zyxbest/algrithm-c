#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  char *str = "nihao, woshi";
  char *s = strstr(str, "nih");
  if (s) {
    printf("havestring %p\n", s);
  } else {
    printf("not hvae");
  }

  return 0;
}
