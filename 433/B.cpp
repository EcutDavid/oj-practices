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

i64 a[(i32)1e5], sa[(i32)1e5], aSum[(i32)1e5 + 1], saSum[(i32)1e5 + 1];

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n; cin >> n;
  REP(i, 0, n) {
    cin >> a[i]; sa[i] = a[i];
  }
  sort(sa, sa + n);

  aSum[0] = 0; saSum[0] = 0;
  REP(i, 1, n + 1) {
    aSum[i] = aSum[i - 1] + a[i - 1];
    saSum[i] = saSum[i - 1] + sa[i - 1];
  }

  i32 t; cin >> t;
  REP(i, 0, t) {
    i32 q, l, r; cin >> q >> l >> r;
    if (q == 1) {
      cout << aSum[r] - aSum[l - 1] << endl;
    } else {
      cout << saSum[r] - saSum[l - 1] << endl;
    }
  }
}
