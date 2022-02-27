#if !defined(DOUBLE_LISTH_H)
#define DOUBLE_LISTH_H

typedef struct DNode
{
    int value;
    struct DNode *pre, *next;
} DNode, *DLinkList;

int initList(DLinkList *list);
int isEmpty(DLinkList list);

#endif // DOUBLE_LISTH_H
