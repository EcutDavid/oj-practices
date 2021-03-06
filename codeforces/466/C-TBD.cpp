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

i32 a[(i32)5e5];

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  i64 sum = 0;
  REP(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  if ((sum % 3) || (n < 3)) {
    cout << 0 << endl;
    return 0;
  }

  vi32 c2;
  vector<pi32> c1;
  i64 tempSum = 0;
  REP(i, 0, n - 1) {
    tempSum += a[i];
    if (tempSum == sum / 3 * 2) c2.push_back(i);
    if (tempSum == sum / 3) c1.push_back({i, c2.size()});
  }

  i64 total = 0;
  TR(c1, it) {
    total += c2.size() - it->second;
  }

  cout << total;
}
