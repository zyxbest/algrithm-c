
#include <iostream>
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
  // 奇数index的链表互相连接, 偶数随后
  // 首位为奇数
  ListNode* oddEvenList(ListNode* head) {
    if (!head) {
      return head;
    }

    ListNode *odd = head, *even = head->next, *tmp = head, *evenHead = even;
    int times = 1;
    while (tmp->next) {
      // 奇数
      if (times % 2) {
        if (times == 1) {
          even = tmp->next;
        } else {
          even->next = tmp->next;
          even = even->next;
        }
      } else {
        // 偶数
        odd->next = tmp->next;
        odd = odd->next;
      }
      // 计数器自增
      times++;
      // 移动到下一个
      tmp = tmp->next;
    }

    if (times > 2) {
      // 偶数列表跟随者奇数链表之后
      odd->next = evenHead;

      // 偶数列表结尾为空e
      even->next = nullptr;
    }
    return head;
  }

  ListNode* simpleSolution(ListNode* head) {
    if (head) {
      ListNode *odd = head, *even = head->next, *evenHead = even;
      while (even && even->next) {
        // 奇偶各自间隔一个相连
        odd->next = odd->next->next;
        even->next = even->next->next;

        // 移动到下一个奇偶
        odd = odd->next;
        even = even->next;
      }
      // 偶数链表放在奇数链表后面
      odd->next = evenHead;
    }
    return head;
  }
};

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
