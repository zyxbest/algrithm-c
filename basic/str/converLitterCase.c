#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *tolower(char *s) {
  char *result = (char *)calloc(strlen(s), sizeof(char));
  for (int i = 0; i < strlen(s); i++) {
    result[i] = tolower((unsigned char)s[i]);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  char s[10];
  scanf("%s", s);
  printf("%s\n", s);

  char *str = tolower(s);
  printf("%s\n", str);
  free(str);
  return 0;
}
