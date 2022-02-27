#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "code03_LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkList L;
    // init(&L);
    // if (isEmpty(L))
    // {
    //     printf("At first L.next %p\n", L->next);
    // }

    insertHead(&L);
    // insertTail(&L);

    printf("insert %d at index 1\n", 3);
    insert(L, 1, 3);
    printList(L);

    int value = delElem(L, 1);
    printf("delete index 1 is %d\n", value);

    printList(L);

    printf("reverse list\n");
    reverseInPlace(L);
    printList(L);

    Node *node = locateElem(L, 4);
    if (node)
    {
        printf("find 3 node: %p next.value %d\n", node, node->next ? node->next->value : -1);
    }

    printf("list lenght is %d\n", length(L));

    return 0;
}

void insertHead(LinkList *list)
{
    int e;
    (*list) = (Node *)malloc(sizeof(Node));
    if (*list == NULL)
    {
        mallocError();
    }

    (*list)->next = NULL;
    scanf("%d", &e);

    while (e != 9999)
    {
        insertNextNode(*list, e);
        scanf("%d", &e);
    }
}

void insertTail(LinkList *list)
{
    int e;
    (*list) = (Node *)malloc(sizeof(Node));
    Node *tail = *list;
    scanf("%d", &e);

    while (e != 9999)
    {
        tail->next = (Node *)malloc(sizeof(Node));
        tail = tail->next;
        tail->value = e;
        scanf("%d", &e);
    }
    tail->next = NULL;
}

void indexBelowError()
{
    printf("index should >= 0");
    exit(EXIT_FAILURE);
}

void init(LinkList *L)
{
    *L = (Node *)malloc(sizeof(Node));
    if (!(*L))
    {
        printf("Init failure, exit program\n");
        exit(EXIT_FAILURE);
    }
    (*L)->next = NULL;
}

int isEmpty(LinkList L)
{
    return L->next == NULL;
}

int insert(LinkList L, int i, int e)
{
    if (i < 0)
    {
        indexBelowError();
    }

    // 从头结点下一个开始
    Node *p = getElem(L, i);
    if (p == NULL)
    {
        printf("index not allowed!");
        exit(EXIT_FAILURE);
    }

    return insertNextNode(p, e);
}

int insertNextNode(Node *p, int e)
{
    if (p == NULL)
    {
        return 0;
    }
    // 新节点
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        return 0;
    }
    node->value = e;

    // 之后的挂到新节点之后
    node->next = p->next;
    p->next = node;
    return 1;
}

void printList(LinkList list)
{
    Node *p = list->next;
    // 在为null之前打印所有的value
    while (p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int delElem(LinkList list, int index)
{
    if (index < 0)
    {
        indexBelowError();
    }
    Node *p = getElem(list, index);
    if (p == NULL || p->next == NULL)
    {
        printf("index not allowed!");
        exit(EXIT_FAILURE);
    }
    int value = p->next->value;
    p->next = p->next->next;
    return value;
}

Node *getElem(LinkList list, int index)
{
    Node *p = list;
    while (p != NULL && index--)
    {
        p = p->next;
    }
    return p;
}

Node *locateElem(LinkList list, int e)
{
    Node *p = list->next;
    while (p != NULL && p->value != e)
    {
        p = p->next;
    }
    return p;
}

int length(LinkList list)
{
    int i = 0;
    while (list->next != NULL)
    {
        i++;
        list = list->next;
    }
    return i;
}

void mallocError()
{
    printf("cant malloc for list\n");
    exit(EXIT_FAILURE);
}

void reverseInPlace(LinkList list)
{
    Node *p = list->next;
    list->next = NULL;

    while (p)
    {
        // 每次暂存一个数据节点
        Node *t = p;
        p = p->next;

        // 暂存节点放在头结点后面
        t->next = list->next;
        list->next = t;
    }
}