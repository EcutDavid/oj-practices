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

typedef unordered_set<int> usi;

void bfs(int node, unordered_map<int, vector<int>> &adj, usi &visited, usi &finished, bool &hasCycle) {
  if (hasCycle) return;
  if (visited.count(node) && !finished.count(node)) {
    hasCycle = true;
    return;
  }
  visited.insert(node);
  for (int d : adj[node]) {
    bfs(d, adj, visited, finished, hasCycle);
  }
  finished.insert(node);
}

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }

  usi visited, finished;

  for (int i = 1; i <= n; i++) {
    if (finished.count(i)) continue;
    bool hasCycle = false;
    bfs(i, adj, visited, finished, hasCycle);
    if (hasCycle) {
      cout << 1 << "\n";
      return 0;
    }
  }

  cout << 0 << "\n";
}