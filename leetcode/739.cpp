#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ret;
    vector<pair<int, int>> s;

    for (int i = T.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.back().first <= T[i]) {
        s.pop_back();
      }
      ret.push_back(
          s.empty() ? 0 : s.back().second - i);
      s.push_back({T[i], i});
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};