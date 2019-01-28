// Yet another prefix sum problem.
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

#define REP(i, a, b) for (i32 i = a; i < b; i++)
#define PB push_back
#define PF push_front

i32 x[(u32)1e3][(u32)1e3];

void solve(i32 n, i32 m) {
  i32 l[n - m + 1]; REP(i, 0, n - m + 1) l[i] = 0;
  REP(i, 0, m) REP(j, 0, m) l[0] += x[i][j];

  REP(i, 1, n - m + 1) {
    l[i] = l[i - 1];
    REP(j, 0, m) {
      l[i] -= x[i - 1][j]; l[i] += x[i - 1 + m][j];
    }
  }

  i32 sum = 0;
  REP(i, 0, n - m + 1) {
    sum += l[i]; cout << l[i] << "\n";

    REP(j, 1, n - m + 1) {
      REP(k, 0, m) {
        l[i] -= x[i + k][j - 1]; l[i] += x[i + k][j - 1 + m];
      }
      sum += l[i]; cout << l[i] << "\n";
    }
  }
  cout << sum << "\n";
}

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n, m; bool isFirst = true;
  while(cin >> n >> m) {
    if (isFirst) isFirst = false;
    else cout << "\n";
    REP(i, 0, n*n) cin >> x[i / n][i % n];
    solve(n, m);
  }
}
