#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return NULL;
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode *result = NULL, *cur = NULL;

    while (l1 && l2) {
      if (l1->val > l2->val) swap(l1, l2);
      if (!result) {
        result = cur = l1;
      } else {
        cur = cur->next = l1;
      }
      l1 = l1->next;
    }

    if (l2) cur->next = l2;
    if (l1) cur->next = l1;

    return result;
  }
};

int main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
}
