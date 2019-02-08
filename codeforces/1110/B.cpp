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

i32 b[(i32)1e5];
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m, k;
  cin >> n >> m >> k;

  REP(i, 0, n) {
    cin >> b[i];
  }

  i32 total = 1;
  if (n > 1) total = b[n - 1] - b[0] + 1;

  vi32 s;
  REP(i, 1, n) {
    if (b[i] - b[i - 1] == 1) continue;
    s.push_back(b[i] - b[i - 1] - 1);
  }

  sort(all(s));
  REP(i, 0, k - 1) {
    // Spent 4 mins on here.
    if (1 + i > s.size()) break;
    total -= s[s.size() - 1 - i];
  }

  cout << total << endl;
}
