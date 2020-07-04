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
#define TR(c, it) for (auto (it) = (c).begin(); (it) != (c).end(); (it)++)

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 t;
  cin >> t;
  REP(i, 0, t) {
    i64 n, r;
    cin >> n >> r;
    i64 niceColCount = min(n - 1, r);
    i64 sum = (1 + niceColCount) * niceColCount / 2;
    if (r > niceColCount) sum++;
    cout << sum << "\n";
  }
}
