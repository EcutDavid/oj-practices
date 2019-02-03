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

//   End with E      End with H
i64 dp1[(i32)1e6], dp2[(i32)1e6];
i64 m = 1000000007;

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 t;
  cin >> t;
  dp1[0] = 1;
  dp2[0] = 1;

  unordered_map<i32, i64> res = {{0, 2}};
  REP(i, 1, (i32)1e6) {
    dp1[i] = dp2[i - 1];
    dp2[i] = (dp1[i - 1] + dp2[i - 1]) % m;
    res[i] = (res[i - 1] + dp1[i] + dp2[i]) % m;
  }
  while (t--) {
    i32 n;
    cin >> n;
    cout << res[n - 1] << "\n";
  }
}
