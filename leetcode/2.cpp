#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto ret = new ListNode(0);
    auto cur = ret;

    int acc = 0;
    while (l1 || l2) {
      int sum = acc + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      cur->val = sum % 10;
      acc = sum / 10;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
      if (l1 || l2 || acc) {
        cur = cur->next = new ListNode(acc);
      }
    }

    return ret;
  }
};