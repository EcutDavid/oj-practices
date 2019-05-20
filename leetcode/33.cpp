#include <vector>

using std::vector;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) return mid;

      if (nums[l] <= nums[r]) {
        if (nums[mid] < target) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
        continue;
      }

      bool midInLeftSegment = nums[mid] >= nums[l];
      if (midInLeftSegment) {
        if (nums[mid] < target || nums[l] > target) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
        continue;
      }

      if (nums[mid] < target && nums[r] >= target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return -1;
  }
};