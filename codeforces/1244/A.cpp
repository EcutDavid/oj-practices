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
  i32 q;
  cin >> q;
  while(q--) {
    i32 a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    i32 pen = a / c + (a % c ? 1 : 0);
    i32 pencil = b / d + (b % d ? 1 : 0);
    if (pen + pencil > k) {
      cout << -1 << "\n";
      continue;
    }
    cout << pen << " " << pencil << "\n";
  }
}
