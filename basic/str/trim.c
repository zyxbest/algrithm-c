#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 以char数组的形式打印字串
void printChar(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    printf("%c ", str[i]);
  }
  printf("\tlength: %d ", strlen(str));
  printf("\n");
}
char *trim(char *s) {
  size_t len = strlen(s);
  int i;
  for (i = 0; i < len; i++) {
    if (s[i] != ' ') {
      s = s + i;
      break;
    }
  }

  len -= i;
  for (i = len; i > 0; i++) {
    if (s[i] != ' ') {
      break;
    } else {
      s[i] = '\0';
    }
  }

  return s;
}

char *trimStr(char *s) {
  size_t len = strlen(s);
  while (isspace(s[len - 1])) {
    --len;
  }
  s[len - 1] = '\0';

  while (*s && isspace(*s)) {
    ++s;
    --len;
  }

  char *res = (char *)malloc((len + 1) * sizeof(char));
  strncpy(res, s, len);
  return res;
}

char *trimString2(char *str) {
  char *end;

  while (isspace((unsigned char)*str))
    str++;

  if (*str == 0)
    return str;

  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end))
    end--;

  end[1] = '\0';

  return str;
}

int main(int argc, char const *argv[]) {
  char s[] = "  niha  owoshi  ";
  // printf("%s\n", trim(s));
  printChar(s);
  printChar(trimStr(s));
  printChar(trimString2(s));
  return 0;
}
