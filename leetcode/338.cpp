#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ret(1, 0);
    for (int i = 1; i <= num; i++) {
      int iCopy = i;
      int bitPos = -1;
      while (iCopy) {
        bitPos++;
        iCopy /= 2;
      }
      ret.push_back(1);
      ret[i] += ret[i - (1 << bitPos)];
    }
    return ret;
  }
};