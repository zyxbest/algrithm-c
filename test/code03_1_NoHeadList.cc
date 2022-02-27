#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node, *LinkList;

// 指针的指针
// 指针指向结构体
// 指针的指针
void initValue(LinkList *L)
{
    *L = NULL;
}

int ifNull(LinkList L)
{
    return L == NULL;
}

int main(int argc, char const *argv[])
{
    LinkList L;

    Node *p;
    printf("p==NULL %d\n", p == NULL);
    printf("%zu\n", L);
    // L =NULL;
    initValue(&L);
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
