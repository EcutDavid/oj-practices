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

  i32 n, m, k;
  cin >> n >> m >> k;
  vector<vi32> c;
  vi32 wTotal = {k};

  REP(i, 0, n) {
    vi32 ci(3, 0);
    REP(j, 0, 3) {
      cin >> ci[j];
    }
    wTotal.push_back(wTotal[wTotal.size() - 1] + ci[1]);
    c.push_back(ci);
  }
  if (k < c[0][0]) {
    cout << -1 << endl;
    return 0;
  }

  unordered_map<i32, vi32> p;
  REP(i, 0, m) {
    i32 x, y;
    cin >> x >> y;
    p[x].push_back(y);
  }
  // Calc order for the castlers.

  vector<vi32> dp;
  dp.push_back({0});
  REP(i, 0, n) {
    if (c[i][0] > wTotal[i]) {
      cout << -1 << endl;
      return 0;
    }
    i32 choiceCount = min(i + 1, wTotal[i] - c[i][0]);
    for (i32 i = 0; i < choiceCount; i++) {
      // Have to make the choice based on whether there are portals.

    }
  }
}
