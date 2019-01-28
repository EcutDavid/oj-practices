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

#define REP(i, a, b) for (auto i = a; i < b; i++)
#define PB push_back
#define PF push_front

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  string s; vi32 b; cin >> s;
  // The size might smaller than 3.
  REP(i, 0, max((i32)(s.size() - 3), 0)) {
    if (s.substr(i, 4) == "bear") b.push_back(i);
  }

  i64 sum = 0; i32 last = b.size() - 1;
  REP(i, 0, b.size()) {
    i64 l = b[i] + 1;
    i64 r = (i == last ? s.size() : (b[i + 1] + 3)) - (b[i] + 3);
    sum += l * r;
  }
  cout << sum << endl;
}
