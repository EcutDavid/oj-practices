#include <algorithm>
#include <vector>

using namespace std;
class Solution {
 private:
  int partition(vector<int>& nums, int target) {
    int p = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < target) {
        swap(nums[i], nums[p]);
        p++;
      }
    }
    // The dutch flag solution...
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        swap(nums[i], nums[p]);
        p++;
      }
    }
    return p - 1;
  }

  int select(vector<int>& nums, int l, int r) {
    vector<int> medians;
    for (int i = l; i <= r; i += 5) {
      int top = min(int(nums.size()) - 1, i + 4);
      sort(nums.begin() + i, nums.begin() + top + 1);
      medians.push_back(nums[(i + top) / 2]);
    }
    if (medians.size() == 1) {
      return medians[0];
    }
    return select(medians, 0, medians.size() - 1);
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    int target = select(nums, 0, nums.size() - 1);

    int targetIndex = partition(nums, target);
    int curK = nums.size() - targetIndex;

    if (curK == k) return target;
    if (curK > k) {
      vector<int> newNums(nums.begin() + targetIndex + 1, nums.end());
      return findKthLargest(newNums, k);
    }
    vector<int> newNums(nums.begin(), nums.begin() + targetIndex);
    return findKthLargest(newNums, k - curK);
  }
};