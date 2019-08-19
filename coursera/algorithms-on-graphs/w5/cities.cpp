#include <math.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;
using std::pair;

double calcDistance(pair<int, int> a, pair<int, int> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  // I missed std::fixed initially.
  std::cout << std::fixed << std::setprecision(10);

  int n;
  cin >> n;
  vector<pair<int, int>> cords(n);
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    cords[i] = { x, y };
  }
  vector<vector<pair<double, int>>> adj(n);
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      adj[i].push_back({ calcDistance(cords[i], cords[j]), j });
    }
  }

  double ret = 0;
  priority_queue<pair<double, int>> q;
  q.push({ 0.0, 0 });

  vector<bool> visited(n);
  while(!q.empty()) {
    auto item = q.top();
    int index = item.second;
    double distance = item.first;
    q.pop();

    if (visited[index]) continue;
    visited[index] = true;
    ret -= distance;

    for (auto d : adj[index]) {
      if (visited[d.second]) continue;
      q.push({ -d.first, d.second });
    }
  }

  cout << ret << std::endl;
}
