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

  i32 n, m;
  cin >> n >> m;
  i32 a[m];
  REP(i, 0, m) {
    cin >> a[i];
  }
  sort(a, a + m);
  i32 totalMove = a[m - 1] - a[0];

  i32 b[m];
  // There are (m - 1) "segments", each piece can reduce exactly one segment.
  REP(i, 0, m - 1) {
    b[i] = a[i + 1] - a[i];
  }
  sort(b, b + m - 1);

  i32 choices = min(m - 1, n - 1);
  REP(i, 0, choices) {
    // b's length is m - 1, need extra (-i - 1) to map the index.
    totalMove -= b[m - i - 2];
  }
  cout << totalMove << endl;
}
