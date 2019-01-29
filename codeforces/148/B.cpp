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
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  double p, d, t, f, c; cin >> p >> d >> t >> f >> c;
  if (p >= d) {
    cout << 0 << endl;
    return 0;
  }

  double cur = p * t; i32 sum = 0;
  while (cur < c) {
    double tAcc = cur / (d - p);

    cur += tAcc * p;
    if (cur >= c) break;
    sum++;
    cur += (cur / d + f) * p;
  }

  cout << sum << endl;
}
