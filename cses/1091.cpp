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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m;
  cin >> n >> m;

  map<i32, i32> p;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    p[num]++;
  }

  REP(i, 0, m) {
    if (p.empty()) {
      cout << -1 << "\n";
      continue;
    }

    i32 m;
    cin >> m;

    auto upper = p.upper_bound(m);
    if (upper == p.begin()) {
      cout << -1 << "\n";
      continue;
    }
    upper--;
    cout << upper->first << "\n";
    upper->second--;
    if (!upper->second) p.erase(upper);
  }
}
