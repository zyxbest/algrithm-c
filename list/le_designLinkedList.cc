#include <cassert>
#include <iostream>
using namespace std;
// 单链表节点
class Node {
 public:
  int val;
  Node* next;
  Node(int val) : val(val), next(NULL){};
};

class MyLinkedList {
 public:
  int size;    // 链表的长度
  Node* head;  // 头结点
  MyLinkedList() : head(nullptr), size(0){};

  int get(int index) {
    // 越界返回-1
    if (index < 0 || index >= size) {
      return -1;
    }

    // 找到第index个node
    Node* curr = head;
    while (index-- > 0) {
      curr = curr->next;
    }
    return curr->val;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    // 错误的话,不插入
    if (index < 0 || index > size) {
      return;
    }
    // 暂存头结点
    Node* temp = head;
    // 插入新节点
    Node* newNode = new Node(val);
    // 头部插入
    if (index == 0) {
      newNode->next = temp;
      head = newNode;
    } else {
      // 非头部插入, 找到目标结点的前一个,美如画
      while (--index > 0) {
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
    }
    // 长度加一
    size++;
  }

  void deleteAtIndex(int index) {
    // 错误跳过
    if (index < 0 || index >= size) {
      return;
    }
    Node *cur = head, *temp;
    // 头结点直接删除
    if (index == 0) {
      head = cur->next;
      temp = cur;
    } else {
      // 非头结点,找到前一个节点,下一个节点即要删除的节点
      while (--index > 0) {
        cur = cur->next;
      }
      // 暂存要删除的节点
      temp = cur->next;
      cur->next = cur->next->next;
    }
    // 释放节点
    delete temp;
    // 调整大小
    size--;
  }

  void output() {
    Node* temp = head;
    cout << "size is " << size << "\t";
    while (temp) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char const* argv[]) {
  MyLinkedList* list = new MyLinkedList();
  assert(list->head == nullptr);
  assert(list->size == 0);

  list->addAtTail(3);
  list->addAtTail(4);
  list->addAtHead(1);
  list->addAtIndex(1, 2);
  list->output();
  cout << list->get(2) << endl;

  list->deleteAtIndex(2);
  list->output();
  return 0;
}
