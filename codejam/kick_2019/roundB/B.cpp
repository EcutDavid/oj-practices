// TODO: this solution is round, figure out how to fix the bugs.
#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 n;
    cin >> n;
    vi32 s(n), e(n), l(n);
    REP(i, 0, n) {
      cin >> s[i] >> e[i] >> l[i];
    }
    i32 sTotal = accumulate(all(s), 0);
    vi32 memoEnd[n];
    vi32 memoBegin[n];

    REP(i, 0, n) {
      memoEnd[i] = vi32(sTotal + 1);
      memoBegin[i] = vi32(sTotal + 1);
      REP(j, 0, sTotal - s[i] + 1) {
        i32 cur = max(0, e[i] - l[i] * j);
        i32 prev = 0;
        i32 next = 0;
        if (i > 0) {
          REP(k, 0, j) {
            prev = max(memoEnd[i - 1][k], prev);
          }
          REP(k, j + s[i], sTotal) {
            next = max(memoBegin[i - 1][k], next);
          }
        }

        memoEnd[i][j + s[i] - 1] = max(
            i > 0 ? memoEnd[i - 1][j + s[i] - 1] : 0,
            prev + cur);
        memoBegin[i][j] = max(
            i > 0 ? memoBegin[i - 1][j] : 0,
            cur + next);
        // PRINT(j);
        // PRINT(j + s[i] - 1);
        // PRINT(memoEnd[i][j + s[i] - 1]);
        // PRINT(memoBegin[i][j]);
      }
    }

    i32 ret = 0;
    REP(i, 0, sTotal) {
      i32 count = memoEnd[n - 1][i];
      if ((i + s[i]) < sTotal && n > 1) {
        count += memoBegin[n - 2][i + 1];
      }
      ret = max(ret, count);
      count = memoBegin[n - 1][i];
      if (i > 0 && n > 1) {
        count += memoEnd[n - 2][i - 1];
      }
      ret = max(ret, count);
    }

    // i32 ret = *max_element(all(memoBegin[n - 1]));
    // i32 ret = *max_element(all(memoEnd[n - 1]));

    cout << "Case #" << t << ": " << ret << "\n";
  }
}
