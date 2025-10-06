#include "list_node.h"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }

    ListNode *prev = head;
    ListNode *curr = head->next;
    prev->next = nullptr;

    while (curr->next->next != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev->next = nullptr;
      prev = curr;
      curr = next;
    }

    return curr;
  }
};
