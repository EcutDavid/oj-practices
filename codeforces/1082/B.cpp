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

i32 getDistance(pi32 p) {
  return p.second - p.first + 1;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  string w;
  cin >> n >> w;

  vector<pi32> g;
  i32 l = -1;
  REP(i, 0, n) {
    if (w[i] == 'G') {
      if (l == -1) l = i;
      continue;
    }
    if (l != -1) {
      g.push_back({l, i - 1});
      l = -1;
    }
  }
  if (l != -1) {
    g.push_back({l, n - 1});
  }

  switch (g.size()) {
    case 0:
      cout << 0 << endl;
      break;
    case 1:
      cout << getDistance(g[0]) << endl;
      break;
    case 2:
      if (g[1].first - g[0].second == 2) {
        cout << getDistance(g[0]) + getDistance(g[1]) << endl;
      } else {
        cout << max(getDistance(g[0]), getDistance(g[1])) + 1 << endl;
      }
      break;
    default:
      i32 best = 0;
      REP(i, 0, g.size() - 1) {
        i32 len = getDistance(g[i]) + 1;
        if (g[i + 1].first - g[i].second == 2) {
          len += getDistance(g[i + 1]);
        }
        best = max(best, len);
      }
      best = max(best, getDistance(g[g.size() - 1]) + 1);
      cout << best << endl;
      break;
  }
}
