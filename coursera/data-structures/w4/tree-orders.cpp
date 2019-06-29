#include <sys/resource.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

// The key has not being reference to is the root
class TreeOrders {
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;
  int root;

 public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    vector<int> refCount(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
      if (left[i] != -1) refCount[left[i]]++;
      if (right[i] != -1) refCount[right[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (refCount[i] == 0) root = i;
    }
  }

  vector<int> in_order() {
    vector<int> result;
    std::function<void(int)> visit;
    visit = [&result, this, &visit](int key) {
      if (key == -1) return;
      visit(this->left[key]);
      result.push_back(this->key[key]);
      visit(this->right[key]);
    };
    visit(root);

    return result;
  }

  vector<int> pre_order() {
    vector<int> result;
    std::function<void(int)> visit;
    visit = [&result, this, &visit](int key) {
      if (key == -1) return;
      result.push_back(this->key[key]);
      visit(this->left[key]);
      visit(this->right[key]);
    };
    visit(root);

    return result;
  }

  vector<int> post_order() {
    vector<int> result;
    std::function<void(int)> visit;
    visit = [&result, this, &visit](int key) {
      if (key == -1) return;
      visit(this->left[key]);
      visit(this->right[key]);
      result.push_back(this->key[key]);
    };
    visit(root);

    return result;
  }
};

void print(vector<int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main(int argc, char **argv) {
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;  // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }

  return main_with_large_stack_space();
}
