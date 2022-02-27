#include <stdio.h>
#include <stdlib.h>
#include "code04_DoubleList.h"
int main(int argc, char const *argv[])
{
    DLinkList L;
    initList(&L);

    if (isEmpty(L))
    {
        printf("first is empty\n");
    }

    return 0;
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
    DNode *p = getElem(list, index);
    DNode *node = (DNode *)malloc(sizeof(DNode));
    insertNextDNode(p->pre, node);
}

/**
 * @brief Get the Elem object
 *
 * @param list
 * @param index
 * @return DNode*
 */
DNode *getElem(DLinkList list, int index)
{
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