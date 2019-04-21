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

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 n, s;
    cin >> n >> s;
    vi32 a(n);
    REP(i, 0, n) {
      cin >> a[i];
    }

    i32 ret = 0;
    REP(i, 0, n) {
      if ((n - i) < ret) break;
      unordered_map<i32, i32> c;
      i32 count = 0;
      REP(j, i, n) {
        if (c[a[j]] == s) {
          count -= s;
          c[a[j]] = -1;
        }
        if (c[a[j]] == -1) continue;
        c[a[j]]++;
        count++;

        ret = max(ret, count);
      }
    }

    cout << "Case #" << t << ": " << ret << "\n";
  }
}
