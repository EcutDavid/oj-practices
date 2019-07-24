#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::queue;
using std::unordered_set;
using std::vector;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int start, end;
  cin >> start >> end;

  vector<int> dis(n + 1, -1);
  dis[start] = 0;

  unordered_set<int> visited = { start };
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int item = q.front();
    q.pop();

    for (int d : adj[item]) {
      if (visited.count(d)) continue;
      visited.insert(d);
      dis[d] = dis[item] + 1;
      q.push(d);
    }
  }

  cout << dis[end] << "\n";
}