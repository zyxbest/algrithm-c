#include <cassert>
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next, *pre;
  ListNode(int x) : val(x), next(nullptr), pre(nullptr){};
};

class MyLinkedList {
 public:
  ListNode *head;
  int size;
  MyLinkedList() {
    head = nullptr;
    size = 0;
  }

  // 找到第几个结点
  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    ListNode *tmp = head;
    while (index-- > 0) {
      tmp = tmp->next;
    }
    return tmp->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }
  void addAtTail(int val) { addAtIndex(size, val); }
  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }

    ListNode *cur = head, *node = new ListNode(val);
    // 头结点
    if (index == 0) {
      node->next = head;
      if (head) {
        head->pre = node;
      }
      head = node;
    } else {
      while (--index > 0) {
        cur = cur->next;
      }
      node->next = cur->next;
      node->pre = cur;

      cur->next = node;
      // 不是尾结点
      if (node->next) {
        node->next->pre = node;
      }
    }
    // 长度加一
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }

    ListNode *tmp = head;
    if (index == 0) {
      head = head->next;
    } else {
      while (--index > 0) {
        tmp = tmp->next;
      }
      tmp->next = tmp->next->next;
      // 删除的是尾结点特殊处理
      if (tmp->next) {
        tmp = tmp->next->pre;
      }
    }
    // 调节链表长度
    size--;
  }

  // 打印链表长度和元素
  void output() {
    ListNode *temp = head;
    cout << "size is " << size << "\t";
    while (temp) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  MyLinkedList *list = new MyLinkedList();
  assert(list->head == nullptr);
  assert(list->size == 0);

  list->addAtHead(3);
  list->addAtTail(2);
  list->addAtTail(5);
  list->addAtHead(4);
  list->addAtIndex(3, 1);

  list->deleteAtIndex(2);
  assert(1 == list->get(2));
  list->deleteAtIndex(3);
  list->deleteAtIndex(2);
  list->output();
  return 0;
}
