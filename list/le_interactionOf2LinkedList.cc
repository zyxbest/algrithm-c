/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr){};
};

class Solution {
 public:
  // 判断无环的两个链表交点在哪
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA, *curB = headB;
    int sizeA = 0, sizeB = 0;
    // 计算两个链表的长度
    while (curA) {
      curA = curA->next;
      sizeA++;
    }
    while (curB) {
      curB = curB->next;
      sizeB++;
    }

    // reset
    curA = headA;
    curB = headB;
    int minus = 0;

    // 让size更大的链表先提前走差值步
    if (sizeA > sizeB) {
      minus = sizeA - sizeB;
      while (minus-- > 0) {
        curA = curA->next;
      }
    } else {
      minus = sizeB - sizeA;
      while (minus-- > 0) {
        curB = curB->next;
      }
    }

    // 如果相等, 就返回交点
    while (curB && curA) {
      // 从头结点开始判断
      if (curB == curA) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }

    // 不相交
    return nullptr;
  }

  ListNode *getShortestSolution(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA, *p2 = headB;

    while (p1 && p2) {
      // 相同表示找到了交点
      if (p1 == p2) {
        return p1;
      }
      // 步进
      p1 = p1->next;
      p2 = p2->next;

      // 只要有一个为空,就把他设为另一个链表的头结点
      // 不可以同时为空,意思就是到了尾结点
      if (!p1) {
        p1 = headB;
      } else if (!p2) {
        p2 = headA;
      }
    }
    return nullptr;
  }
};