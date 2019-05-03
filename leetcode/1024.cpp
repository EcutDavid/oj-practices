#include <vector>

using std::vector;

class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    int cur = 0;
    int ret = 0;
    while (cur < T) {
      vector<int> best;
      for (auto d : clips) {
        if (d[0] > cur || d[1] <= cur) continue;
        if (best.empty() || best[1] < d[1]) {
          best = d;
        }
      }
      if (best.empty()) return -1;
      cur = best[1];
      ret++;
    }
    return ret;
  }
};