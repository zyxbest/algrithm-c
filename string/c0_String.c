#include "c0_String.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief 赋值
 *
 * @param s 串
 * @param chars 要赋值给串的字符串
 */
void assign(String *s, char *chars) {
  strcpy(s->data, chars);
  s->length = strlen(chars);
}

void copyString(String *s, String p) {
  assign(s, p.data);
  s->length = p.length;
}

int isEmpty(String s) { return s.length == 0; }

int length(String s) { return s.length; }

void destroy(String *s) {
  assign(s, "");
  s->length = 0;
}
void clear(String *s) { s->length = 0; }

void concat(String *s, String t1, String t2) {
  strncat(s->data, t1.data, t1.length);
  strncat(s->data, t2.data, t2.length);
  s->length = t1.length + t2.length;
}

int main(int argc, char const *argv[]) {
  String s = {.data = "helloworld", .length = 10};

  assign(&s, "woshisheii");
  printf("%s\n", s.data);
  assert(s.length == 10);

  String *p = (String *)malloc(sizeof(String));
  copyString(p, s);
  printf("%s\n", p->data);
  assert((*p).length == 10);
  assert(isEmpty(*p) == 0);
  assert(length(*p) == 10);

  String *cat = (String *)malloc(sizeof(String));
  // concat(cat, s, *p);
  strncat(cat->data, s.data, s.length);
  printf("concat: %s\n", cat->data);

  clear(p);
  assert((*p).length == 0);

  destroy(&s);
  assert(isEmpty(s) == 1);
  return 0;
}
