#include "include/le_commonListFunction.h"

class Solution {
 public:
  Node *flatten(Node *head) {
    Node *tmp = head, *next;
    stack<Node *> st;
    while (tmp->next || !st.empty()) {
      if (tmp->child) {
        next = tmp->next;
        st.push(next);
        tmp->next = tmp->child;
        tmp->child = nullptr;
        tmp->next->prev = tmp;
      }
      tmp = tmp->next;

      next = st.top();
      st.pop();
      tmp->next = next;
    }
  }
};

int main(int argc, char const *argv[]) {
  Node *head;
  Solution *s;
  s->flatten(head);
  return 0;
}
