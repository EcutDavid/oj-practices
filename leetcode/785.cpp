// Check is a graph bipartite.
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& g) {
    vector<int> c(g.size());
    vector<int> done(g.size());

    for (int i = 0; i < g.size(); i++) {
      if (done[i]) continue;
      done[i] = true;
      if (c[i] == 0) c[i] = 1;
      queue<int> q;
      q.push(i);

      while (!q.empty()) {
        int item = q.front();
        q.pop();

        for (auto x : g[item]) {
          if (c[x] == c[item]) return false;
          c[x] = c[item] == 1 ? 2 : 1;

          if (!done[x]) {
            done[x] = true;
            q.push(x);
          }
        }
      }
    }

    return true;
  }
};