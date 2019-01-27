// 1. Calc the count of choices each item to be 3n + 0, 3n + 1, 3n + 2
// 2. an 3 * 3 loop to go through the array.
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

i64 m = (int)1e9 + 7;

i32 main() {
  i64 n, l, r; cin >> n >> l >> r;
  i64 c[3] = {};
  i32 v = r / 3 - (l + 2) / 3;
  REP(i, 0, 3) c[i] = v;

  c[1] += (l % 3 == 1) ? 1 : 0;
  c[2] += (l % 3 >= 1) ? 1 : 0;

  c[0] += ((r % 3) >= 0) ? 1 : 0;
  c[1] += ((r % 3) >= 1) ? 1 : 0;
  c[2] += ((r % 3) >= 2) ? 1 : 0;

  i64 ans[3];
  REP(i, 0, 3) ans[i] = c[i];
  REP(i, 1, n) {
    i64 oldAns[3];
    REP(j, 0, 3) {
      oldAns[j] = ans[j];
      ans[j] = 0;
    }
    REP(j, 0, 3) {
      REP(k, 0, 3) {
        i32 tar = (j + k) % 3;
        ans[tar] = (ans[tar] + oldAns[j] * c[k]) % m;
      }
    }
  }

  cout << ans[0] << endl;
}