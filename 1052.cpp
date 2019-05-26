#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
    int retOri = 0;
    for (int i = 0; i < c.size(); i++) {
      if (!g[i]) retOri += c[i];
    }

    vector<int> pre(c.size() + 1);
    for (int i = 0; i < c.size(); i++) {
      pre[i + 1] = pre[i] + (g[i] ? c[i] : 0);
    }

    int ret = 0;
    for (int i = 0; i < (c.size() - X + 1); i++) {
      int extra = pre[i + X] - pre[i];
      ret = max(ret, retOri + extra);
    }
    return ret;
  }
};
