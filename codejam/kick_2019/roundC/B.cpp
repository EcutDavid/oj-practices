#include <bits/stdc++.h>
using namespace std;

typedef int i32;
typedef vector<i32> vi32;

#define REP(i, a, b) for (auto i = a; i < b; i++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 0, T) {
    i32 R, C, K;
    cin >> R >> C >> K;
    vi32 b[R];
    REP(i, 0, R) {
      b[i] = vi32(C);
      REP(j, 0, C) {
        cin >> b[i][j];
      }
    }

    vi32 validLen[R];
    REP(i, 0, R) {
      REP(j, 0, C) {
        i32 vMax = b[i][j];
        i32 vMin = b[i][j];
        i32 best = 1;
        REP(k, j + 1, C) {
          vMax = max(vMax, b[i][k]);
          vMin = min(vMin, b[i][k]);
          if (vMax - vMin > K) break;
          best++;
        }
        validLen[i].push_back(best);
      }
    }

    i32 ret = R;
    REP(i, 2, C + 1) {
      REP(j, 0, C + 1 - i) {
        i32 cur = 0;
        REP(k, 0, R) {
          if (validLen[k][j] < i) {
            cur = 0;
          } else {
            cur += i;
            ret = max(ret, cur);
          }
        }
      }
    }

    cout << "Case #" << t + 1 << ": " << ret << "\n";
  }
}
