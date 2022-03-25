#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 10
int main(int argc, char const *argv[]) {
  char *str1;

  str1 = (char *)malloc(sizeof(char) * Maxsize);
  scanf("%7s", str1);
  printf("%s\n", str1);

  free(str1);
  return 0;
}
