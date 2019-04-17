#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int ret = 0;
    int prevMax = 0;
    for (auto it = p.rbegin(); it != p.rend(); it++) {
      ret = max(ret, prevMax - *it);
      prevMax = max(prevMax, *it);
    }
    return ret;
  }
};
