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
  vi32 c;
  i64 sum = 0;
  REP(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  if ((sum % 3) || (n < 3)) {
    cout << 0 << endl;
    return 0;
  }

  i64 tempSum = 0;
  REP(i, 0, n) {
    if (a[i] == 0 && !c.empty() && sum != 0) {
      c[c.size() - 1]++;
      continue;
    }

    tempSum += a[i];
    if (tempSum == sum / 3) {
      tempSum = 0;
      c.PB(1);
    }
  }
  if (!c.empty() && (sum != 0)) c[c.size() - 1] = 1;

  vi32 suffixSum(c.size() + 1, 0);
  REP(i, 0, c.size()) {
    i32 index = c.size() - i - 1;
    suffixSum[index] = suffixSum[index + 1];
    suffixSum[index] += c[index];
  }

  i64 total = 0;
  REP(i, 0, max((i32)(c.size() - 1), 0)) {
    if (i == (c.size() - 2)) {
      if (sum != 0) continue;  // Need at least two parts to continue.
    }
    total += (i64)c[i] * (i64)(suffixSum[i + 1] - 1);
  }

  cout << total << endl;
}
