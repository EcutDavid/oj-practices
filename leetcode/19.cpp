#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int sum = 0;
    auto cur = head;
    while (cur) {
      sum++;
      cur = cur->next;
    }
    if (sum == n) return head->next;

    cur = head;
    for (int i = 0; i < (sum - n - 1); i++) {
      cur = cur->next;
    }
    cur->next = cur->next->next;
    return head;
  }
};