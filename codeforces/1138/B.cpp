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

  i32 n;
  cin >> n;
  vector<bool> cVal(n), aVal(n);
  string cs, as;
  cin >> cs >> as;

  REP(i, 0, n) {
    cVal[i] = cs[i] == '1';
    aVal[i] = as[i] == '1';
  }

  vi32 c, a, b, none;
  REP(i, 0, n) {
    if (cVal[i] && !aVal[i]) c.push_back(i + 1);
    if (!cVal[i] && aVal[i]) a.push_back(i + 1);
    if (cVal[i] && aVal[i]) b.push_back(i + 1);
    if (!cVal[i] && !aVal[i]) none.push_back(i + 1);
  }

  i32 cMax = c.size() + b.size();
  REP(i, 0, n / 2 + 1) {
    // Validate total i that good at C works
    if (i > cMax) break;

    REP(j, 0, i + 1) {
      if (j > b.size()) break;
      if (c.size() < (i - j)) continue;

      i32 rest = n / 2 - i;
      i32 aMax = b.size() - j + a.size();
      i32 diff = aMax - i;
      if (diff < 0) break;

      // Rest can be used to choose A or N
      if ((diff > rest) || (diff > a.size())) continue;
      if (rest - diff > none.size()) continue;

      bool hadOutput = false;
      REP(k, 0, i - j) {
        cout << (hadOutput ? " " : "") << c[k];
        hadOutput = true;
      }
      REP(k, 0, j) {
        cout << (hadOutput ? " " : "") << b[k];
        hadOutput = true;
      }
      REP(k, 0, diff) {
        cout << (hadOutput ? " " : "") << a[k];
        hadOutput = true;
      }
      REP(k, 0, rest - diff) {
        cout << (hadOutput ? " " : "") << none[k];
        hadOutput = true;
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
