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

  i32 n, l, r, x;
  cin >> n >> l >> r >> x;

  vi32 a(n);
  REP(i, 0, n) {
    cin >> a[i];
  }

  i32 ceil = 1 << n, total = 0;

  REP(i, 3, ceil) {
    i32 iCopy = i, index = 0, s = 0, elMin = i32(1e9), elMax = -1;

    while (iCopy) {
      if (iCopy & 1) {
        elMin = min(a[index], elMin);
        elMax = max(a[index], elMax);
        s += a[index];
      }
      index++;
      iCopy /= 2;
    }

    if ((s >= l) && (s <= r) && (elMax - elMin >= x))
      total++;
  }
  cout << total << endl;
}
