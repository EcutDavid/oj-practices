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
    i32 n;
    string f;
    cin >> n >> f;
    i32 ret = n;
    i32 left = -1, right = -1;
    REP(i, 0, n) {
      if (f[i] == '1') {
        left = left == -1 ? i : left;
        right = i;
      }
    }

    if (left != -1) {
      ret = max(ret, right + 1 + right + 1);
      ret = max(ret, right + 1 + n - right);
      ret = max(ret, n - left + left + 1);
      ret = max(ret, n - left + n - left);
    }

    cout << ret << "\n";
  }
}
