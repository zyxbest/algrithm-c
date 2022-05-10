#include "include/le_commonListFunction.h"

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1, *p2 = l2;
    int val = 0;
    while (p1 || p2) {
      // 有值的话, 就可以加上去
      val += p1 ? p1->val : 0 + p2 ? p2->val : 0;
      if (val > 9) {
        // 进位
        p1->val = val % 10;
        val = 1;
      } else {
        // 不进位
        p1->val = val;
        val = 0;
      }

      // 为空的话,不变
      if (p1) {
        p1 = p1->next;
      }
      if (p2) {
        p2 = p2->next;
      }
    }
    return p1;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> arr1{2, 4, 3}, arr2{5, 6, 4};

  ListNode *head1 = generateLinkedList(arr1);
  ListNode *head2 = generateLinkedList(arr2);

  Solution *s;
  ListNode *head = s->addTwoNumbers(head1, head2);
  print(head);
  return 0;
}
