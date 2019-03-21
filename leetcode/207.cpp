// Finding circle in a graph.
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visiting, vector<bool>& done, int index) {
  visiting[index] = true;

  for (auto i : adj[index]) {
    if (done[i]) continue;
    if (visiting[i]) return false;

    bool ret = dfs(adj, visiting, done, i);
    if (!ret) return ret;
  }

  done[index] = true;
  return true;
}

class Solution {
 public:
  bool canFinish(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (auto p : prerequisites) {
      adj[p.second].push_back(p.first);
    }
    vector<bool> visiting(n), done(n);
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      bool ret = dfs(adj, visiting, done, i);
      if (!ret) return ret;
    }
    return true;
  }
};