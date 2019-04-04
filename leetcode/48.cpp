#include <vector>
using namespace std;

pair<int, int> genNextPos(pair<int, int> pos, int n) {
  return {pos.second, n - 1 - pos.first};
}

class Solution {
 public:
  void rotate(vector<vector<int>>& m) {
    int n = m.size();
    int ic = (n + 1) / 2;
    int jc = n / 2;

    for (int i = 0; i < ic; i++) {
      for (int j = 0; j < jc; j++) {
        pair<int, int> cur = {i, j};
        pair<int, int> next = cur;

        for (int k = 0; k < 3; k++) {
          next = genNextPos(next, n);
          // [a, b, c, d] -> [d, a, b, c]
          swap(m[cur.first][cur.second], m[next.first][next.second]);
        }
      }
    }
  }
};