#include <bits/stdc++.h>
using namespace std;

typedef int i32;

#define REP(i, a, b) for (auto i = a; i < b; i++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  REP(i, 1, n + 1) {
    string row;
    cin >> row;
    i32 lCount = row.size() - 1;
    i32 fCount = 0;
    for (char c : row) {
      fCount += c == 'B';
    }
    bool works = (fCount != lCount) && ((fCount * 2 >= lCount) || fCount >= 2);
    cout << "Case #" << i << ": " << (works ? "Y" : "N") << "\n";
  }
}
