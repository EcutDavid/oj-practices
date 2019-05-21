#include <stack>

using namespace std;

class MyQueue {
 private:
  stack<int> pushS;
  stack<int> popS;

  void flushPushS() {
    while (!pushS.empty()) {
      popS.push(pushS.top());
      pushS.pop();
    }
  }

 public:
  /** Initialize your data structure here. */
  MyQueue() {
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    pushS.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ret = peek();
    popS.pop();
    return ret;
  }

  /** Get the front element. */
  int peek() {
    if (popS.empty()) {
      flushPushS();
    }
    return popS.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return pushS.empty() && popS.empty();
  }
};
