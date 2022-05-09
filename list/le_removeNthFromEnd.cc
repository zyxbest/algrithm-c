/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode* next) : val(x), next(next){};
};

class Solution {
 public:
  // 删掉链表倒数第几个节点
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // fast 快指针,以及要删除的暂存
    ListNode *fast = head, *slow = head;
    // fast提前走n步
    while (n-- > 0) {
      fast = fast->next;
    }

    // fast 为空, 表示要删除的节点是头结点
    if (!fast) {
      fast = head;
      head = head->next;
    } else {
      // fast一直走到最后一个节点
      // slow走到要删除的前一个节点
      while (fast->next) {
        fast = fast->next;
        slow = slow->next;
      }
      // 删除slow的下一个节点
      fast = slow->next;
      slow->next = slow->next->next;
    }
    delete fast;
    return head;
  }
};