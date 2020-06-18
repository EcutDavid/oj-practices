#include <bits/stdc++.h>
using namespace std;

#define pi32 pair<int, int>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pi32, vector<pi32>, greater<pi32>> q;
    for (int i = 0; i < lists.size(); i++) {
      if (!lists[i]) continue;
      q.push({lists[i]->val, i});
    }
    ListNode* retHead = nullptr;
    ListNode* retTail = nullptr;

    while (!q.empty()) {
      pi32 d = q.top();
      q.pop();
      if (!retHead) {
        retHead = lists[d.second];
        retTail = lists[d.second];
      } else {
        retTail->next = lists[d.second];
        retTail = retTail->next;
      }
      lists[d.second] = lists[d.second]->next;
      if (!lists[d.second]) continue;
      q.push({lists[d.second]->val, d.second});
    }

    return retHead;
  }
};
