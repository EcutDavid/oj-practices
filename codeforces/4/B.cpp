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

  i32 d, t;
  cin >> d >> t;
  i32 timeMin = 0, timeMax = 0;
  vector<pi32> days;
  REP(i, 0, d) {
    i32 x, y;
    cin >> x >> y;
    timeMin += x;
    timeMax += y;
    days.PB({x, y});
  }
  if (t < timeMin || t > timeMax) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES\n";
  i32 extraTotal = t - timeMin;
  REP(i, 0, d) {
    i32 extra = min(days[i].second - days[i].first, extraTotal);
    extraTotal -= extra;
    cout << (i == 0 ? "" : " ") << days[i].first + extra;
  }
  cout << endl;
}
