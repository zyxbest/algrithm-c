#include "le_commonListFunction.h"

class Solution {
 public:
  // 合并两个有序链表
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // head 锚点, newHead 真实的头结点
    ListNode *p1 = list1, *p2 = list2, *head = new ListNode(),
             *newHead = head->next;
    while (p1 && p2) {
      // 谁小链接到head的下一个值
      if (p1->val > p2->val) {
        head->next = p2;
        p2 = p2->next;
      } else {
        head->next = p1;
        p1 = p1->next;
      }
      head = head->next;
    }

    // 剩下的直接相连
    if (p1) {
      head->next = p1;
    }

    if (p2) {
      head->next = p2;
    }

    delete head;
    return newHead;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr1 = {1, 2, 4};
  vector<int> arr2 = {1, 3, 4};
  ListNode* head1 = generateLinkedList(arr1);
  ListNode* head2 = generateLinkedList(arr2);

  print(head1);

  Solution* s;
  ListNode* head = s->mergeTwoLists(head1, head2);
  print(head);
  return 0;
}
