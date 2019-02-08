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
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

const i32 m = 1000000007;
i32 calcWays(i32 n, i32 k) {
  vi32 dp(n + 1);
  dp[0] = 1;
  REP(i, 1, n + 1) {
    REP(j, 1, k + 1) {
      if ((i - j) < 0) continue;
      dp[i] = (dp[i] + dp[i - j]) % m;
    }
  }
  return dp[n];
}

i32 main() {
  i32 n, k, d;
  cin >> n >> k >> d;
  i32 total = calcWays(n, k), sub = calcWays(n, d - 1);
  cout << ((sub > total) ? (total + m - sub) : (total - sub)) << endl;
}
