
#include "list_node.h"
using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
      return list2;
    } else if (!list2) {
      return list1;
    }

    if (list1->val <= list2->val)
      list1->next = list2;
    list1 = list1->next;
  }
  else {
    list2->next = list1;
    list2 = list2->next;
  }
}
}
;
