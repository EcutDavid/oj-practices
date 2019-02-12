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

const i32 m = 1000000007;

i32 main() {
  i32 n, k;
  cin >> n >> k;

  unordered_map<i32, vector<i32>> fac;
  REP(i, 1, n + 1) {
    // dp[n] represents the value contributed by i itself before a new round.
    // so we don't have to worry about i is not a factor.
    REP(j, 1, i) {
      if (i % j == 0) fac[i].push_back(j);
    }
  }

  vector<i32> dp(n + 1, 1);

  REP(i, 1, k) {
    REP(j, 1, n + 1) {
      i32 num = n + 1 - j;
      TR(fac[num], it) {
        dp[num] = (dp[num] + dp[*it]) % m;
      }
    }
  }

  i32 sum = 0;
  REP(j, 1, n + 1) {
    sum = (sum + dp[j]) % m;
  }

  cout << sum << endl;
}
