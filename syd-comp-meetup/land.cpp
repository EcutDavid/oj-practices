#include <bits/stdc++.h>
using namespace std;

typedef int i32;

#define REP(i, a, b) for (auto i = a; i < b; i++)
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  vector<vector<bool>> land;
  string row;
  while (cin >> row) {
    if (row == "") continue;
    vector<bool> vals;
    TR(row, it) {
      vals.push_back(*it == '1');
    }
    land.push_back(vals);
  }

  vector<map<pair<i32, i32>, bool>> range;
  REP(i, 0, land.size()) {
    map<pair<i32, i32>, bool> q;
    REP(j, 0, row.size()) {
      q[{j, j}] = land[i][j];
    }
    REP(j, 0, row.size()) {
      REP(k, j + 1, row.size()) {
        q[{j, k}] = q[{j, k - 1}] && land[i][k];
      }
    }
    range.push_back(q);
  }

  i32 best = 0;
  REP(i, 1, row.size() + 1) {
    REP(j, 0, row.size() - i + 1) {
      i32 cur = 0;
      REP(k, 0, land.size()) {
        if (range[k][{j, j + i - 1}])
          cur += i;
        else
          cur = 0;
        best = max(best, cur);
      }
    }
  }

  cout << "Result: " << best << endl;
}
