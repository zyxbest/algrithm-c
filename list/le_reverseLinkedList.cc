#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Solution {
 public:
  //
  ListNode *reverseList(ListNode *head) {
    ListNode *newHead = nullptr, *next;
    while (head) {
      next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }

  // 递归
  ListNode *reverseListRecursive(ListNode *head) {
    return process(head, nullptr);
  }

  ListNode *process(ListNode *head, ListNode *newHead) {
    if (!head) {
      return newHead;
    }

    ListNode *next = head->next;
    head->next = newHead;
    return process(next, head);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> oddArr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  ListNode* head = generateLinkedList(arr);
  ListNode* oddHead = generateLinkedList(oddArr);

  print(head);

  Solution* s;
  s->oddEvenList(head);
  s->oddEvenList(oddHead);

  print(head);
  print(oddHead);
  return 0;
}