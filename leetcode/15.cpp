// TODO: improve the time complexity.
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    map<int, set<pair<int, int>>> memo;

    for (int i = 0; i < (int(nums.size()) - 2); i++) {
      if (nums[i] > 0) break;
      int l = i + 1, r = nums.size() - 1;
      while (l != r) {
        int sum = nums[l] + nums[r];
        if (sum == -nums[i]) {
          memo[nums[i]].insert({nums[l], nums[r]});
          l++;
        } else if (sum > -nums[i]) {
          r--;
        } else {
          l++;
        }
      }
    }

    vector<vector<int>> ret;
    for (auto it = memo.begin(); it != memo.end(); it++) {
      for (auto p : it->second) {
        ret.push_back(vector<int>{it->first, p.first, p.second});
      }
    }
    return ret;
  }
};