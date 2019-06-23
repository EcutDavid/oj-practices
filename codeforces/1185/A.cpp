#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef vector<i32> vi32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  vi32 a(3);
  i32 d;
  REP(i, 0, 3) {
    cin >> a[i];
  }
  cin >> d;
  sort(all(a));
  i64 ret = 0;
  ret += max(0, d - (a[1] - a[0]));
  ret += max(0, d - (a[2] - a[1]));

  cout << ret << endl;
}
