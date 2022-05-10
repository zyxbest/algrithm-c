#if !defined(COMMON_LIST_FUNNCTION)
#define COMMON_LIST_FUNNCTION
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
// 单链表结点定义
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* generateLinkedList(vector<int> arr);
void print(ListNode* head);

#endif  // COMMON_LIST_FUNNCTION
