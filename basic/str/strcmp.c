#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const char *str1 = "hello there 1";
  const char *str2 = "hello there 2";
  const char *str3 = "Hello there 2";

  !strcmp(str1, str2) ? printf("strings are equal\n")
                      : printf("strings are not equal\n");

  !strcmp(str1, str3) ? printf("strings are equal\n")
                      : printf("strings are not equal\n");

  printf("%d\n", strcmp(str3, str2));

  const char *str4 = "hello there 2";
  !strcmp(str2, str4) ? printf("strings are equal\n")
                      : printf("strings are not equal\n");
  exit(EXIT_SUCCESS);
}