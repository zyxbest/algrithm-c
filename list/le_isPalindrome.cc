#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  static ListNode* tmp;
  // 回文链表,使用stack
  bool isPalindrome(ListNode* head) {
    if (head) {
      ListNode *fast = head, *slow = head;
      // 找到中点node
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      // checkNext()
      stack<ListNode*> arr;
      while (slow) {
        arr.push(slow);
        slow = slow->next;
      }

      fast = head;

      while (!arr.empty()) {
        slow = arr.top();
        if (slow->val != fast->val) {
          return false;
        }
        arr.pop();
        fast = fast->next;
      }
    }

    return true;
  }

  bool isPalindromeNoStack(ListNode* head) {
    if (head) {
      ListNode *fast = head, *slow = head;
      // 找到中点node
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      fast = head;
      slow = reverse(slow);
      while (slow) {
        if (fast->val != slow->val) {
          return false;
        }
        slow = slow->next;
        fast = fast->next;
      }
    }
    return true;
  }

  // 翻转链表
  ListNode* reverse(ListNode* head) {
    ListNode* newHead = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }

  // 递归检查是否是回文链表
  bool isPalindromeRecursive(ListNode* head) {
    this->tmp = head;
    return check(head);
  }

  bool check(ListNode* head) {
    if (!head) return true;
    // 递归到尾结点
    bool res = check(head->next) && (tmp->val == head->val);
    tmp = tmp->next;
    return res;
  }
};

ListNode* Solution::tmp = nullptr;
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

int main(int argc, char const* argv[]) {
  vector<int> arr{1, 2, 3, 4, 4, 3, 2, 1};
  vector<int> oddArr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  ListNode* head = generateLinkedList(arr);
  ListNode* oddHead = generateLinkedList(oddArr);

  print(head);

  Solution* s;
  assert(true == s->isPalindromeRecursive(head));
  print(head);
  print(oddHead);
  return 0;
}
