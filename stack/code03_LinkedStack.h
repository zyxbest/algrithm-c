#if !defined(code03_LinkedStack)
#define code03_LinkedStack
#include <assert.h>
typedef struct LNode {
  int value;
  struct LNode *next;
} LNode, *LStack;

LStack createStack();
int isEmpty(LStack s);
int pop(LStack s);

// test
void testCreateStack();
#endif // code03_LinkedStack
