#include "list_node.h"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (!head)
      return nullptr;

    if (!head->next)
      return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;       // Move slow by 1
      fast = fast->next->next; // Move fast by 2
    }

    return slow;
  }
};
