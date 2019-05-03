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
  vector<i64> v(n);
  REP(i, 0, n) {
    cin >> v[i];
  }

  vector<pair<i64, i64>> m(n - 1);
  m[0].first = v[0] + v[1];
  m[0].second = -m[0].first;

  REP(i, 1, n - 1) {
    m[i].first = max(m[i - 1].first, m[i - 1].second) + v[i + 1];
    m[i].second = max(
        m[i - 1].first - 2 * v[i],
        m[i - 1].second + 2 * v[i]);
    ;
    m[i].second -= v[i + 1];
  }
  cout << max(m[n - 2].first, m[n - 2].second) << endl;
  return 0;
}
