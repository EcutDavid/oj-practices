// Small case only
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
#define PRINT(x) cout << #x ": " << (x) << endl
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10)
#define CASE(i, result) cout << "Case #" << i << ": " << (result) << "\n"

const i64 M = 1000000007;

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 t;
  cin >> t;

  REP(i, 1, t + 1) {
    i64 n, k, x, y, c, d, e1, e2, f;
    cin >> n >> k >> x >> y >> c >> d >> e1 >> e2 >> f;

    vi32 a(1, (x + y) % f);
    REP(j, 1, n) {
      i64 newX = (c * x + d * y + e1) % f;
      i64 newY = (d * x + c * y + e2) % f;
      a.push_back((newX + newY) % f);
      x = newX;
      y = newY;
    }

    unordered_map<i32, unordered_map<i32, i64>> ki;
    REP(j, 1, n + 1) {
      ki[1][j] = j;
    }
    REP(j, 2, k + 1) {
      REP(d, 1, n + 1) {
        ki[j][d] = ki[j - 1][d] * d % M;
      }
    }

    i64 total = 0;

    REP(j, 1, k + 1) {
      REP(d, 1, n + 1) {
        REP(e, 0, n + 1 - d) {
          i64 cur = 0;
          REP(p, e, e + d) {
            cur = (cur + a[p] * ki[j][p - e + 1]) % M;
          }
          total = (total + cur) % M;
        }
      }
    }

    CASE(i, total);
  }
}
