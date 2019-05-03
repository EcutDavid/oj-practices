#include <vector>
using std::vector;

class MinStack {
 private:
  vector<int> content;
  vector<int> mins;

 public:
  void push(int x) {
    content.push_back(x);
    if (mins.empty()) {
      mins.push_back(x);
      return;
    }
    if (mins.back() >= x) mins.push_back(x);
  }

  void pop() {
    int val = content.back();
    content.pop_back();
    if (val == mins.back()) mins.pop_back();
  }

  int top() {
    return content.back();
  }

  int getMin() {
    return mins.back();
  }
};
