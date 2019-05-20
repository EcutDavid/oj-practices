#include <vector>

using std::vector;

class Solution {
 private:
  int findRep(vector<int> &repVec, int index) {
    while (repVec[index] != index) {
      index = repVec[index];
    }
    return index;
  }

  void join(vector<int> &repVec, vector<int> &sizeVec, int i, int j) {
    repVec[j] = i;
    sizeVec[i] += sizeVec[j];
  }

 public:
  int findCircleNum(vector<vector<int>> &M) {
    int count = M.size();
    int ret = count;
    vector<int> repVec(count);
    for (int i = 0; i < count; i++) {
      repVec[i] = i;
    }
    vector<int> sizeVec(count, 1);

    for (int i = 0; i < count; i++) {
      for (int j = 0; j < count; j++) {
        if (i == j || M[i][j] == 0) continue;
        int iRep = findRep(repVec, i);
        int jRep = findRep(repVec, j);
        if (iRep == jRep) continue;
        ret--;
        if (sizeVec[iRep] >= sizeVec[jRep]) {
          join(repVec, sizeVec, iRep, jRep);
        } else {
          join(repVec, sizeVec, jRep, iRep);
        }
      }
    }
    return ret;
  }
};