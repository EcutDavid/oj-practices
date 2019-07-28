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

// No idea on how to solve the large case yet,
// Current solution, choose the position for warehouse n times,
// after w is choosen, calc the cost for putting n - 1 stalls, and choosen the best k ones.
// Total time: n ^ 2 * log(n)
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 k, n;
    cin >> k >> n;
    vector<i64> x(n), c(n);
    REP(i, 0, n) {
      cin >> x[i];
    }
    REP(i, 0, n) {
      cin >> c[i];
    }
    i64 best = 1e18;
    REP(i, 0, n) {
      i64 total = c[i];
      vector<i64> cost;
      REP(j, 0, n) {
        if (j == i) continue;
        cost.push_back(c[j] + abs(x[i] - x[j]));
      }
      sort(all(cost));
      REP(j, 0, k) {
        total += cost[j];
      }
      best = min(best, total);
    }
    cout << "Case #" << t << ": " << best << "\n";
  }
}
