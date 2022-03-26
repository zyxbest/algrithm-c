#if !defined(DOUBLE_LISTH_H)
#define DOUBLE_LISTH_H

typedef struct DNode {
  int value;
  struct DNode *pre, *next;
} DNode, *DLinkList;

void printList(DLinkList list);
int initList(DLinkList *list);
int isEmpty(DLinkList list);
void initTail(DLinkList *list);
DNode *getElem(DLinkList list, int index);
void insertNextDNode(DNode *p, DNode *s);
void insertAtIndex(DLinkList list, int index, int e);
int deleteNextDNode(DNode *node);
void destroyList(DLinkList list);
#endif // DOUBLE_LISTH_H
