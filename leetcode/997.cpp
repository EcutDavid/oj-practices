#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> inDeg(N + 1), outDeg(N + 1);
    for (auto p : trust) {
      outDeg[p[0]]++;
      inDeg[p[1]]++;
    }

    int judge = -1;
    for (int i = 1; i <= N; i++) {
      if (outDeg[i] != 0 || inDeg[i] != (N - 1)) continue;
      if (judge != -1) return -1;

      judge = i;
    }

    return judge;
  }
};