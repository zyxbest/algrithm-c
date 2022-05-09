struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  //  删除值为val的节点
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* node = head;
    // 头结点是val的话, 就移动到下一个节点
    while (node && node->val == val) {
      node = node->next;
      head = node;
    }

    while (node && node->next) {
      // 如果下一个是val, 就删除node->next
      if (node->next->val == val) {
        node->next = node->next->next;
      } else {
        // 如果下一个不是val, 就跳到该位置
        node = node->next;
      }
    }
    return head;
  }
};