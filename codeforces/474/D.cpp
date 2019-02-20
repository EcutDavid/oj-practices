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
const i32 caseMax = 1e5 + 1;
i32 dp[caseMax];
i32 pre[caseMax];
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  pre[0] = dp[0] = 1;

  i32 n, k;
  cin >> n >> k;

  REP(i, 1, caseMax) {
    dp[i] = dp[i - 1];
    if (i >= k) {
      dp[i] = (dp[i] + dp[i - k]) % m;
    }
  }

  REP(i, 1, caseMax) {
    pre[i] = (pre[i - 1] + dp[i]) % m;
  }

  REP(i, 0, n) {
    i32 a, b;
    cin >> a >> b;
    i32 left = pre[a - 1], right = pre[b] + (pre[a - 1] > pre[b] ? m : 0);
    cout << right - left << "\n";
  }
}
