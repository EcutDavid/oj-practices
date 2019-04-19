// Interestingly, I initially thought my solution is so bad,
// there must be a O(nlgn) solution, but it seems there isn't one.
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& vs) {
    vector<bool> merged(vs.size());
    for (int i = 0; i < vs.size(); i++) {
      for (int j = i + 1; j < vs.size(); j++) {
        if (vs[i][0] > vs[j][1] || vs[i][1] < vs[j][0]) continue;

        merged[i] = true;
        vs[j][0] = min(vs[j][0], vs[i][0]);
        vs[j][1] = max(vs[j][1], vs[i][1]);
        break;
      }
    }
    vector<vector<int>> ret;
    for (int i = 0; i < vs.size(); i++) {
      if (merged[i]) continue;
      ret.push_back(vs[i]);
    }
    return ret;
  }
};
