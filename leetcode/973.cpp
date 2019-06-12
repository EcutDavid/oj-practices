#include <algorithm>
#include <utility>
#include <vector>

using std::pair;
using std::sort;
using std::vector;

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<pair<int, int>> valueAndIndex;
    for (int i = 0; i < points.size(); i++) {
      int value = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      valueAndIndex.push_back({value, i});
    }
    sort(valueAndIndex.begin(), valueAndIndex.end());

    vector<vector<int>> ret;
    for (int i = 0; i < K; i++) {
      ret.push_back(points[valueAndIndex[i].second]);
    }
    return ret;
  }
};