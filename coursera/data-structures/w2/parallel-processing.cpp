#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef long long i64;

using std::greater;
using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

typedef pair<i64, int> Thread;

int main() {
  int n, m;
  std::cin >> n >> m;
  priority_queue<Thread, vector<Thread>, greater<Thread>> threads;

  for (int i = 0; i < n; i++) {
    threads.push({0, i});
  }

  for (int i = 0; i < m; i++) {
    int t;
    std::cin >> t;

    auto thread = threads.top();
    std::cout << thread.second << " " << thread.first << "\n";

    thread.first += t;
    threads.pop();
    threads.push(thread);
  }
}