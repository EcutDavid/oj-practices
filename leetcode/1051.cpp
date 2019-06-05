#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> cp = heights;
    sort(cp.begin(), cp.end());
    int ret = 0;
    for (int i = 0; i < cp.size(); i++) {
      if (cp[i] != heights[i]) ret++;
    }
    return ret;
  }
};
