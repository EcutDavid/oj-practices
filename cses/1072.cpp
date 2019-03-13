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

  i32 n;
  cin >> n;

  vector<i64> a(max(3, n + 1));
  a[2] = 12;

  REP(i, 3, n + 1) {
    i64 prevBlock = (i - 1) * (i - 1), curBlock = i * i, sum = a[i - 1];

    REP(j, 1, i + 1) {
      i64 slot = prevBlock + curBlock - 1;
      REP(dy, -2, 3) {
        i32 y = j + dy;
        if (dy == 0 || y < 1 || y > i) continue;
        slot -= (y == i ? 1 : 2);
      }
      sum += slot * ((j == i) ? 1 : 2);
    }
    a[i] = sum;
  }

  REP(i, 1, n + 1) {
    cout << a[i] / 2 << "\n";
  }
}
