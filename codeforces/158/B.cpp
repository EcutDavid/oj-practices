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
  i32 n, sum = 0;
  i32 c[4] = {};
  cin >> n;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    if (num != 4)
      c[num]++;
    else
      sum++;
  }

  sum += c[3];
  c[1] -= min(c[1], c[3]);

  sum += c[2] / 2;
  if (c[2] % 2) {
    // For got the case (2, 1) cost me one more submit.
    c[1] -= min(c[1], 2);
    sum++;
  }

  sum += c[1] / 4 + (c[1] % 4 ? 1 : 0);

  cout << sum << endl;
}
