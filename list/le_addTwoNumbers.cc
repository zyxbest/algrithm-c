#include "include/le_commonListFunction.h"

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1, *p2 = l2;
    int val = 0;
    while (p1->next || p2->next) {
      // 有值的话, 就可以加上去
      val += ((p1 ? p1->val : 0) + (p2 ? p2->val : 0));
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
      if (p1 && p1->next) {
        p1 = p1->next;
      }
      if (p2 && p2->next) {
        p2 = p2->next;
      }
    }
    if (val) {
      p1->next = new ListNode(val);
    }

    return l1;
  }
};

void test(vector<int> arr1, vector<int> arr2) {
  ListNode *head1 = generateLinkedList(arr1);
  ListNode *head2 = generateLinkedList(arr2);
  Solution *s;
  ListNode *head = s->addTwoNumbers(head1, head2);
  print(head);
}

int main(int argc, char const *argv[]) {
  // test(vector<int>{9, 9, 9, 9, 9, 9, 9}, vector<int>{9, 9, 9, 9});
  test(vector<int>{2, 4, 3}, vector<int>{5, 6, 4});
  return 0;
}
