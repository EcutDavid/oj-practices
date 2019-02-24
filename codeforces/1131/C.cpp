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

i32 getDiff(vi32& c) {
  i32 diff = 0;

  REP(i, 0, c.size() - 1) {
    if (i == 0) {
      i32 d = max(abs(c[i] - *(c.end() - 1)), abs(c[i] - c[i + 1]));  // |C| > 1, (c.end() - 1) != c.begin
      diff = max(d, diff);
      continue;
    }
    diff = max(diff, abs(c[i] - c[i + 1]));
  }

  return diff;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  vi32 c(n);
  REP(i, 0, n) {
    cin >> c[i];
  }
  sort(all(c));

  i32 bestDiff = getDiff(c);
  vi32& best = c;

  REP(i, 2, c.size()) {
    vi32 cCopy = c;
    reverse(cCopy.end() - i, cCopy.end());
    i32 diff = getDiff(cCopy);
    if (diff < bestDiff) {
      bestDiff = diff;
      best = cCopy;
    }
  }

  REP(i, 0, n) {
    cout << (i == 0 ? "" : " ") << best[i];
  }
  cout << endl;
}
