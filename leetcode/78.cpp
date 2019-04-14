#include <bits/stdc++.h>
using namespace std;

void genS(int level, vector<int>& path, vector<int>& nums, vector<vector<int>>& ret) {
  if (level == nums.size()) {
    ret.push_back(path);
    return;
  }
  path.push_back(nums[level]);
  genS(level + 1, path, nums, ret);
  path.pop_back();
  genS(level + 1, path, nums, ret);
}

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> path;
    genS(0, path, nums, ret);
    return ret;
  }
};