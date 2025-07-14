#include "list_node.h"
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
      return nullptr;
    }

    if (!head->next) {
      return nullptr;
    }

    int count = 0;
    ListNode *temp = head;
    while (temp) {
      temp = temp->next;
      count++;
    }

    int idx = count - n;

    ListNode *res = head;
    if (idx == 1) {
      return res->next;
    } else {
      for (int i = 0; i <= idx - 1; i++) {
        res = res->next;
      }
      ListNode *prev = res;
      res = res->next;
      if (res->next) {
        prev->next = res->next;

      } else {
        prev->next = nullptr;
      }

      return res;
    }
  }
};
