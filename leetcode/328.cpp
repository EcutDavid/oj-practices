#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head) return head;
    if (!head->next) return head;

    ListNode *oddHead = NULL, *oddTail = NULL;
    ListNode *evenHead = NULL, *evenTail = NULL;
    bool isOdd = true;

    while (head) {
      if (isOdd) {
        if (oddHead)
          oddTail->next = head;
        else
          oddHead = head;
        oddTail = head;
      } else {
        if (evenHead)
          evenTail->next = head;
        else
          evenHead = head;
        evenTail = head;
      }
      head = head->next;
      isOdd = !isOdd;
    }
    evenTail->next = NULL;
    oddTail->next = evenHead;
    return oddHead;
  }
};