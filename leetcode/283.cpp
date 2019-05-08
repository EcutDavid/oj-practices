#include <vector>

using std::vector;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int p = 0, zCount = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        zCount++;
      else
        nums[p++] = nums[i];
    }
    for (int i = 0; i < zCount; i++) {
      nums[p + i] = 0;
    }
  }
};