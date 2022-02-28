#include <stdio.h>
#include <stdlib.h>
#include "code04_DoubleList.h"
int main(int argc, char const *argv[])
{
    DLinkList L;
    // initList(&L);

    // if (isEmpty(L))
    // {
    //     printf("first is empty\n");
    // }

    initTail(&L);
    printList(L);
    insertAtIndex(L, 1, 2);
    printList(L);
    DNode *node = getElem(L, 1);
    printf("node at index 1 is node.value: %d\n", node->value);
    destroyList(L);
    int value = deleteNextDNode(node);
    printf("delete index 1' next is node.value: %d\n", value);
    printList(L);
    return 0;
}

void printList(DLinkList list)
{
    while (list->next != NULL)
    {
        printf("%d ", list->next->value);
        list = list->next;
    }
    printf("\n");
}

/**
 * @brief 清空列表
 *
 * @param list
 */
void destroyList(DLinkList list)
{
    DNode *p = list;
    while (p->next != NULL)
    {
        deleteNextDNode(p);
        p = p->next;
    }
}

/**
 * @brief 删除指定结点的下一个节点
 *
 * @param node 指定节点
 * @return int 返回删除节点的值
 */
int deleteNextDNode(DNode *node)
{
    DNode *temp = node->next;
    if (temp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int value = temp->value;
    node->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->pre = node;
    }
    free(temp);
    return value;
}

/**
 * @brief insert a Node at index
 *
 * @param list
 * @param index
 * @param e
 */
void insertAtIndex(DLinkList list, int index, int e)
{
    if (index < 0)
    {
        exit(EXIT_FAILURE);
    }

    DNode *p = getElem(list, index);
    DNode *node = (DNode *)malloc(sizeof(DNode));
    if (node == NULL)
    {
        exit(EXIT_FAILURE);
    }
    node->value = e;

    insertNextDNode(p->pre, node);
}

/**
 * @brief Get the index element
 *
 * @param list
 * @param index
 * @return DNode*
 */
DNode *getElem(DLinkList list, int index)
{
    if (index < 0)
    {
        return NULL;
    }

    DNode *p = list->next;
    while (index-- > 0 && p != NULL)
    {
        p = p->next;
    }
    return p;
}

/**
 * @brief 在p节点之后插入新节点s
 *
 * @param p
 * @param s
 */
void insertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    if (p->next != NULL)
    {
        p->next->pre = s;
    }
    p->next = s;
    s->pre = p;
}

/**
 * @brief 尾插法创建双链表
 *
 * @param list
 */
void initTail(DLinkList *list)
{
    *list = (DNode *)malloc(sizeof(DNode));
    if (*list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    (*list)->pre = NULL;

    DNode *p = *list;
    int e;
    scanf("%d", &e);
    while (e != 999)
    {
        p->next = (DNode *)malloc(sizeof(DNode));
        p->next->pre = p;
        p = p->next;
        p->value = e;
        scanf("%d", &e);
    }
    p->next = NULL;
}

/**
 * @brief 初始化链表
 *
 * @param list
 * @return int
 */
int initList(DLinkList *list)
{
    *list = (DNode *)malloc(sizeof(DNode));
    if (*list == NULL)
    {
        return 0;
    }

    (*list)->next = NULL;
    (*list)->pre = NULL;
    return 1;
}

int isEmpty(DLinkList list)
{
    return list->next == NULL;
}