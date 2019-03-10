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

  i64 n, T;
  cin >> n >> T;
  vi32 a(n);
  REP(i, 0, n) {
    cin >> a[i];
  }

  i64 total = 0;
  // I think there are at most log2(1e18) -> 60 times of iterations.
  while (true) {
    vi32 sub;
    i64 sum = 0;
    TR(a, it) {
      if (sum + *it > T) continue;
      sub.push_back(*it);
      sum += *it;
    }
    if (sub.empty()) break;
    total += sub.size() * (T / sum);
    T %= sum;
  }

  cout << total << endl;
}
