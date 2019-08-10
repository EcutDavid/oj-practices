#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::priority_queue;
using std::unordered_set;
using std::vector;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
  }

  int start, end;
  cin >> start >> end;
  //                  dis   id
  priority_queue<pair<int, int>> q;
  q.push({0, start});
  vector<int> distance(n + 1, 1e9);
  distance[start] = 0;

  while (!q.empty()) {
    int id = q.top().second;
    int curDistance = distance[id];
    q.pop();

    for (auto d : adj[id]) {
      int newDistance = curDistance + d.second;
      if (distance[d.first] <= newDistance) continue;
      distance[d.first] = newDistance;
      q.push({-newDistance, d.first});
    }
  }

  cout << (distance[end] == 1e9 ? -1 : distance[end]) << std::endl;
}