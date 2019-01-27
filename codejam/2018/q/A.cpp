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

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n; cin >> n;
  REP(i, 1, n + 1) {
    vi32 s; i32 c = 0, d; cin >> d;
    string p; cin >> p;

    REP(j, 0, p.size()) {
      if (p[j] == 'C') c++;
      else s.PB(c);
    }

    i32 sum = 0, op = 0;
    while (true) {
      sum = 0;
      REP(j, 0, s.size()) sum += pow(2, s[j]);

      if (sum <= d) break;

      sort(s.begin(), s.end());
      if (s[s.size() - 1] == 0) break;
      s[s.size() - 1]--; op++;
    }

    cout << "Case #" << i << ": " << (sum > d ? "IMPOSSIBLE" : to_string(op)) << "\n";
  }
}
