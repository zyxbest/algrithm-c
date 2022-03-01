#if !defined(ARRAY_STACK_H)
#define ARRAY_STACK_H

#define MAXSIZE 10
typedef struct SNode
{
    int data[MAXSIZE];
    int top;
} SNode,*SqStack;

void initStack(SqStack *s);
void destroyStack(SqStack *s);

void push(SqStack s, int x);
int pop(SqStack s, int *x);
int getTop(SqStack s, int *x);
int isEmpty(SqStack s);
int isFull(SqStack s);

#endif // ARRAY_STACK_H
