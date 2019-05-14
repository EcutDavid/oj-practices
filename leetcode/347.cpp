#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> m;
    for (auto num : nums) {
      m[num]++;
    }
    priority_queue<pair<int, int>> q;
    for (auto d : m) {
      q.push({d.second, d.first});
    }
    vector<int> ret;
    for (int i = 0; i < k; i++) {
      ret.push_back(q.top().second);
      q.pop();
    }

    return ret;
  }
};