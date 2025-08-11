#include "list_node.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    int carry{}, sum{};
    ListNode *curr = head;
    while (l1->next) {
      sum = l1->val + l2->val + carry;
      carry = (sum > 9) ? sum % 10 : 0;
      sum = sum / 10;

      ListNode *temp = new ListNode(sum);
      curr->next = temp;
      curr = curr->next;

      l1 = l1->next;
      l2 = l2->next;
    }

    return head->next;
  }
};
