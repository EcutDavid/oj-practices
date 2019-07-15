#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
using std::queue;
using std::reverse;
using std::unordered_map;
using std::unordered_set;
using std::vector;

typedef unordered_set<int> usi;

void bfs(int node, unordered_map<int, vector<int>> &adj, usi &visited, vector<int> &reversedOrder) {
	if (visited.count(node)) return;
	visited.insert(node);

	for (int d : adj[node]) {
		bfs(d, adj, visited, reversedOrder);
	}
	reversedOrder.push_back(node);
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

  usi visited;
  vector<int> reversedOrder;

  for (int i = 1; i <= n; i++) {
    if (visited.count(i)) continue;
    bfs(i, adj, visited, reversedOrder);
  }
  reverse(reversedOrder.begin(), reversedOrder.end());

  for (int i = 0; i < n; i++) {
    cout << (i > 0 ? " " : "") << reversedOrder[i];
  }

  cout << std::endl;
}
