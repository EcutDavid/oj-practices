#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

// Output 1 if there is any neg cycle.
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> edges(m);
  for (int i = 0; i < m; i++) {
    edges[i] = vector<int>(3);

    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  vector<int> distance(n + 1, 1e9);

  for (int i = 1; i <= n; i++) {
    if (distance[i] != 1e9) continue;
    distance[i] = 0;

    for (int j = 1; j < n; j++) {
      bool shouldStop = true;
      for (auto e : edges) {
        if (distance[e[0]] == 1e9) continue;
        int newDistance = distance[e[0]] + e[2];
        if (newDistance >= distance[e[1]]) continue;
        distance[e[1]] = newDistance;
        shouldStop = false;
      }
      if (shouldStop) break;
    }
    bool haveNegCycle = false;
    for (auto e : edges) {
      if (distance[e[0]] == 1e9) continue;
      int newDistance = distance[e[0]] + e[2];
      if (newDistance >= distance[e[1]]) continue;
      distance[e[1]] = newDistance;
      haveNegCycle = true;
    }
    if (haveNegCycle) {
      cout << 1 << std::endl;
      return 0;
    }
  }
  cout << 0 << std::endl;
}