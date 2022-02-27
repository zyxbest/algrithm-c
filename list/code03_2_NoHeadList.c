#include <stdlib.h>
#include <stdio.h>
typedef struct LNode
{
    int value;
    struct LNode *next;
} LNode, *LinkList;

void initValue(LinkList L)
{
    L = NULL;
}

int ifNull(LNode *L)
{
    return L == NULL;
}

void setNull(LNode *L)
{

    L = NULL;
}

int main(int argc, char const *argv[])
{
    LNode *L;
    // L =NULL;
    setNull(L);
    if (ifNull(L))
    {
        printf("Null");
    }
    else
    {
        printf("Not Null");
    }

    // initValue(&L);
    // printf("L.next == NULL %d\n", L == NULL);
    return 0;
}
