#include "include/le_commonListFunction.h"

class Solution {
 public:
  // 合并两个有序链表
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // head 锚点, newHead 真实的头结点
    ListNode *p1 = list1, *p2 = list2, *head = nullptr, *newHead;
    while (p1 && p2) {
      // 谁小链接到head的下一个值
      if (p1->val > p2->val) {
        if (head) {
          head->next = p2;
          head = head->next;
        } else {
          head = p2;
          // 保存头结点
          newHead = head;
        }
        p2 = p2->next;
      } else {
        if (head) {
          head->next = p1;
          head = head->next;
        } else {
          head = p1;
          // 保存头结点
          newHead = head;
        }
        p1 = p1->next;
      }
    }

    // 剩下的直接相连
    newHead ? head->next : head = p1 ? p1 : p2;
    return newHead;
  }

  ListNode* shortSolution(ListNode* list1, ListNode* list2) {
    ListNode *p1 = list1, *p2 = list2, *fake = new ListNode(INT32_MIN),
             *tail = fake;
    while (p1 && p2) {
      if (p1->val < p2->val) {
        tail->next = p1;
        p1 = p1->next;
      } else {
        tail->next = p2;
        p2 = p2->next;
      }
      tail = tail->next;
    }
    tail->next = p1 ? p1 : p2;
    return fake->next;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr1 = {};
  vector<int> arr2 = {1};
  ListNode* head1 = generateLinkedList(arr1);
  ListNode* head2 = generateLinkedList(arr2);

  print(head1);

  Solution* s;
  ListNode* head = s->shortSolution(head1, head2);
  print(head);
  return 0;
}
