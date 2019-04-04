#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> counter(3, 0);
    for (int num : nums) {
      counter[num]++;
    }
    int cur = 0;
    for (int i = 0; i < 3; i++) {
      while (counter[i]--) {
        nums[cur++] = i;
      }
    }
  }
};