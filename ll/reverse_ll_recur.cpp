
#include "list_node.h"

class Solution {
public:
  void reorderList(ListNode *head) { reorder(head, head->next); }

private:
  ListNode *reorder(ListNode *head, ListNode *curr) {
    if (!curr) {
      return head;
    }

    head = reorder(head, curr->next);

    ListNode *temp = nullptr;
    if (head->next == curr || head == curr) {
      curr->next = nullptr;
    } else {
      temp = head->next;
      head->next = curr;
      curr->next = temp;
    }

    return temp;
  }
};
