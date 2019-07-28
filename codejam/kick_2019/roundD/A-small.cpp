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

// Update the nums and do validations(n times),
// each validation(genSubinterval) would cost n ^ 2, good enough for the small case.

bool isBitEven(i32 num) {
  bool ret = true;
  while (num) {
    if (num & 1) ret = !ret;
    num /= 2;
  }
  return ret;
}

i32 genSubinterval(vi32 &a) {
  i32 ret = 0;

  REP(i, 0, a.size()) {
    i32 cur = a[i];

    REP(j, i, a.size()) {
      if (j != i) {
        cur ^= a[j];
      }
      if (isBitEven(cur)) {
        ret = max(ret, j - i + 1);
      }
    }
  }

  return ret;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 n, q;
    cin >> n >> q;
    vi32 a(n);
    REP(i, 0, n) {
      cin >> a[i];
    }
    cout << "Case #" << t << ": ";
    REP(i, 0, q) {
      i32 index, value;
      cin >> index >> value;
      a[index] = value;
      i32 ret = genSubinterval(a);
      cout << (i > 0 ? " " : "") << ret;
    }
    cout << "\n";
  }
}
