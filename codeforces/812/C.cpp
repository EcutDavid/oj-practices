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

  i64 n, s;
  cin >> n >> s;

  vector<i64> a(n), b(n);
  REP(i, 0, n) {
    cin >> a[i];
  }

  i64 best = 0, cost = 0, l = 1, r = n;
  while (l <= r) {
    i64 mid = (l + r) / 2;
    REP(i, 0, n) {
      b[i] = a[i] + mid * (i + 1);
    }
    sort(all(b));
    i64 spend = 0;
    REP(i, 0, mid) {
      spend += b[i];
      if (spend > s) break;
    }

    if (spend <= s) {
      l = mid + 1;
      if (mid > best) {
        best = mid;
        cost = spend;
      }
    } else {
      r = mid - 1;
    }
  }

  cout << best << " " << cost << endl;
}
