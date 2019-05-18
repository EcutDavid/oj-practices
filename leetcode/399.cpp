#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  double bfs(unordered_map<string, unordered_map<string, double>>& adj, string start, string end) {
    unordered_set<string> visited;
    visited.insert(start);
    queue<string> q;
    q.push(start);
    unordered_map<string, double> distance;
    distance[start] = 1.0;

    while (!q.empty()) {
      string task = q.front();
      if (task == end) return distance[task];
      q.pop();

      for (auto d : adj[task]) {
        if (visited.count(d.first)) continue;
        visited.insert(d.first);
        q.push(d.first);
        distance[d.first] = distance[task] * d.second;
      }
    }

    return -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
    unordered_map<string, unordered_map<string, double>> adj;
    for (int i = 0; i < e.size(); i++) {
      auto eq = e[i];
      adj[eq[0]][eq[1]] = double(1.0) / v[i];
      adj[eq[1]][eq[0]] = v[i];
    }

    vector<double> ret;
    for (auto d : q) {
      if (adj[d[0]].empty() || adj[d[1]].empty()) {
        ret.push_back(-1.0);
        continue;
      }
      if (d[0] == d[1]) {
        ret.push_back(1.0);
        continue;
      }
      ret.push_back(bfs(adj, d[1], d[0]));
    }
    return ret;
  }
};