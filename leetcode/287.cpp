#include <vector>
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int l = 1, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int midCount = 0, sCount = 0, bCount = 0;
      for (int n : nums) {
        if (n == mid) midCount++;
        if (n < mid) sCount++;
        if (n > mid) bCount++;
      }
      if (midCount > 1) return mid;
      if (bCount >= (nums.size() - mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
};