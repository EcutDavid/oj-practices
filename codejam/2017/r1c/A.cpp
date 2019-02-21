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
  MAX_PRECISION

  i32 t;
  cin >> t;
  REP(i, 0, t) {
    i32 n, k;
    cin >> n >> k;

    vector<pair<i64, i64>> p;
    REP(j, 0, n) {
      i64 r, h;
      cin >> r >> h;
      p.push_back({r, h});
    }

    sort(all(p));

    set<pair<i64, i32>> side;
    REP(j, 0, k - 1) {
      side.insert({2 * p[j].first * p[j].second, j});
    }

    i64 best = 0;
    REP(j, k - 1, n) {
      auto baseR = p[j].first, baseH = p[j].second;
      i64 result = baseR * baseR + 2 * baseH * baseR;

      auto it = side.end();
      REP(d, 0, k - 1) {
        it--;
        result += it->first;
      }
      best = max(best, result);
      side.insert({2 * baseH * baseR, j});
    }

    cout << "Case #" << i + 1 << ": " << M_PI * double(best) << "\n";
  }
}
