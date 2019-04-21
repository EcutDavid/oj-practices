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

bool canBeP(vector<i32> &a, vector<i32> &b) {
  i32 oddCount = 0;
  REP(i, 0, 26) {
    if ((b[i] - a[i]) % 2) oddCount++;
    if (oddCount > 1) return false;
  }
  return true;
}

bool alreadyP(string &b, i32 x, i32 y) {
  REP(i, 0, (y - x) / 2) {
    if (b[x + i] != b[y - i]) return false;
  }
  return true;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    i32 n, q;
    string b;
    cin >> n >> q >> b;

    vector<i32> pre[n + 1];
    pre[0] = vector<i32>(26, 0);
    REP(i, 1, n + 1) {
      pre[i] = pre[i - 1];
      pre[i][b[i - 1] - 'A']++;
    }

    i32 count = 0;
    REP(i, 0, q) {
      i32 x, y;
      cin >> x >> y;
      if (canBeP(pre[x - 1], pre[y])) count++;
      // if (!alreadyP(b, x - 1, y - 1)) count++;
    }

    cout << "Case #" << t << ": " << count << "\n";
  }
}
