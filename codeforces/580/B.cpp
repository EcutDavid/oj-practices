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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n, d;
  cin >> n >> d;
  vector<pi32> f(n);
  REP(i, 0, n) {
    i32 m, v;
    cin >> m >> v;
    f[i] = {m, v};
  }
  sort(all(f));

  auto front = f.begin(), back = f.begin();
  i64 cur = 0;
  while (back != f.end()) {
    if ((back->first - front->first) >= d) break;
    cur += back->second;
    back++;
  }

  i64 best = cur;
  while (front != f.end() && back != f.end()) {
    if ((back->first - front->first) >= d) {
      cur -= front->second;
      front++;
    } else {
      cur += back->second;
      best = max(cur, best);
      back++;
    }
  }
  cout << best << endl;
}
