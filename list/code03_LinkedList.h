#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct Node
{
    int value;
    struct Node *next;
} Node, *LinkList;

Node *getElem(LinkList list, int index);

/**
 * @brief 插入到指定节点的下一个
 *
 * @param p
 * @param e
 * @return int
 */
int insertNextNode(Node *p, int e);
/**
 * @brief 头插法建立链表
 *
 * @param list
 */
void insertHead(LinkList *list);

/**
 * @brief 尾插法建立链表
 *
 * @param list
 */
void insertTail(LinkList *list);

/**
 * @brief 数组下标越 下限 报错
 *
 */
void indexBelowError();

/**
 * @brief 分配内存失败报错
 *
 */
void mallocError();

/**
 * @brief 初始化LinkList
 *
 * @param L 单链表
 */
void init(LinkList *L);
int isEmpty(LinkList L);
/**
 * @brief 插入节点
 *
 * @param L list
 * @param i index
 * @param e 值
 */
int insert(LinkList L, int i, int e);

/**
 * @brief 打印list
 *
 * @param list
 */
void printList(LinkList list);

/**
 * @brief 删除一个节点
 *
 * @param list
 * @param index
 * @return int
 */
int delElem(LinkList list, int index);

/**
 * @brief 按值查找
 *
 * @param list 链表
 * @param e 值
 * @return Node* 节点
 */
Node *locateElem(LinkList list, int e);

/**
 * @brief 链表长度
 *
 * @param list
 * @return int
 */
int length(LinkList list);

/**
 * @brief 原地逆置链表
 *
 * @param list
 */
void reverseInPlace(LinkList list);
#endif // LINK_LIST_H
