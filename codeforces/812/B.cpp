// TODO: improve the code via recursion
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

  i32 n, m;
  cin >> n >> m;
  vector<bool> f[n];
  bool shouldSkip = true;
  i32 skipedN = 0;
  REP(i, 0, n) {
    string row;
    cin >> row;
    f[i] = vector<bool>(m + 2, false);
    REP(j, 0, m + 2) {
      if (row[j] == '1') {
        shouldSkip = false;
        f[i][j] = true;
      }
    }
    if (shouldSkip) skipedN++;
  }
  reverse(f, f + n);
  n = max(1, n - skipedN);

  i32 gRight = 0;
  REP(j, 0, m + 1) {
    if (f[0][j]) gRight = j;
  }
  if (n == 1) {
    cout << gRight << endl;
    return 0;
  }

  vi32 l(n), r(n);
  l[0] = gRight * 2 + 1;
  r[0] = m + 2;

  REP(i, 1, n) {
    i32 leftMost = 0, rightMost = 0;
    REP(j, 1, m + 1) {
      if (f[i][j]) rightMost = j;
      if (f[i][m + 1 - j]) leftMost = j;
    }
    if (i < n - 1) {
      l[i] = min(r[i - 1] + m + 2, l[i - 1] + rightMost * 2 + 1);
      r[i] = min(l[i - 1] + m + 2, r[i - 1] + leftMost * 2 + 1);
    } else {
      i32 best = min(l[i - 1] + rightMost, r[i - 1] + leftMost);
      cout << best << endl;
    }
  }
}
