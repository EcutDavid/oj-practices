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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m;
  cin >> n >> m;

  i32 segbase = i32(pow(2.0, ceil(log2(double(n)))));
  vi32 seg(segbase * 2);
  REP(i, 0, n) {
    i32 h;
    cin >> h;
    seg[segbase + i] = h;
  }

  REP(i, 0, segbase) {
    i32 index = segbase - 1 - i;
    seg[index] = max(seg[index * 2 + 1], seg[index * 2]);
  }

  REP(i, 0, m) {
    cout << (i == 0 ? "" : " ");

    i32 q;
    cin >> q;
    i32 index = 1;
    while ((index < segbase) && (seg[index] >= q)) {
      index = index * 2 + (seg[index * 2] >= q ? 0 : 1);
    }

    if (index < segbase) {
      cout << 0;
      continue;
    }

    cout << index - segbase + 1;
    seg[index] -= q;
    while (index > 1) {  // seg[0]'s value does not matter, don't have to be updated.
      index /= 2;
      seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
    }
  }
}
