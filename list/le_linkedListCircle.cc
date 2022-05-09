#include <iostream>
using namespace std;
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
  ListNode(int x) : val(x), next(NULL){};
};

class Solution {
 public:
  /* 使用双指针
  判断链表有没有环 */
  bool hasCycle(ListNode *head) {
    // 快慢指针
    ListNode *fast = head, *slow = head;
    while (fast && slow) {
      // 走到终点
      if (!fast->next) {
        return false;
      }

      fast = fast->next->next;
      slow = slow->next;
      // 相遇即有环
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }

  /* 找出环开始的地方 */
  ListNode *detectCycle(ListNode *head) {
    ListNode *tmp = head, *fast = head, *low = head;
    while (fast && low) {
      if (!fast->next) {
        return NULL;
      }
      fast = fast->next->next;
      low = low->next;

      // 有环
      if (fast == low) {
        // 初始点和入口点的距离 == 慢指针和入口点的距离
        while (low != tmp) {
          low = low->next;
          tmp = tmp->next;
        }
        return low;
      }
    }

    return NULL;
  }
};
int main(int argc, char const *argv[]) { return 0; }
