#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int vToI(vector<int>& cells) {
    int ret = 0;
    for (int i = 0; i < 8; i++) {
      if (cells[i] == 0) continue;
      ret += 1 << i;
    }
    return ret;
  }

  vector<int> iToV(int cVal) {
    vector<int> ret(8);
    for (int i = 0; i < 8; i++) {
      if ((cVal & (1 << i)) == 0) continue;
      ret[i] = 1;
    }
    return ret;
  }

  int grow(int cVal) {
    int ret = 0;
    for (int i = 1; i < 7; i++) {
      int l = cVal & (1 << (i + 1));
      int r = cVal & (1 << (i - 1));
      if ((!l && r) || (l && !r)) continue;
      ret += 1 << i;
    }
    return ret;
  }

 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    int cVal = vToI(cells);
    vector<int> cVals;
    unordered_map<int, int> vIndexMap;
    int counter = 0;
    while (!vIndexMap.count(cVal)) {
      if (counter == N) return iToV(cVal);
      cVals.push_back(cVal);
      vIndexMap[cVal] = counter;
      cVal = grow(cVal);
      counter++;
    }
    int begin = vIndexMap[cVal];
    int loopLen = counter - begin;
    return iToV(cVals[(N - begin) % loopLen + begin]);
  }
};