#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int u, v;
  cin >> u >> v;

  unordered_set<int> visited = {u};
  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int item = q.front();
    q.pop();
    if (item == v) {
      cout << 1 << "\n";
      return 0;
    }

    for (auto d : adj[item]) {
      if (visited.count(d)) continue;
      visited.insert(d);
      q.push(d);
    }
  }

  cout << 0 << "\n";
}