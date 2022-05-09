#include "le_commonListFunction.h"

// 打印链表
void print(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// 根据数组产生一个链表
ListNode* generateLinkedList(vector<int> arr) {
  ListNode *head = nullptr, *temp = nullptr;
  for (auto& v : arr) {
    if (head) {
      // 接下去
      temp->next = new ListNode(v);
      temp = temp->next;
    } else {
      // head 未初始化
      head = temp = new ListNode(v);
      // head = temp;
    }
  }
  return head;
}