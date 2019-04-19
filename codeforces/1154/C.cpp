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

vector<vi32> rules = {
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1},
    {-1, 0, 0},
    {0, 0, -1},
    {0, -1, 0},
    {-1, 0, 0},
};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  vector<i64> f(3);
  REP(i, 0, 3) {
    cin >> f[i];
  }
  i32 minWeeks = min(min(f[0] / 3, f[1] / 2), f[2] / 2);

  f[0] -= minWeeks * 3;
  f[1] -= minWeeks * 2;
  f[2] -= minWeeks * 2;

  i32 best = 0;
  REP(i, 0, 7) {
    vector<i64> fCopy = f;
    REP(j, 0, 6) {
      bool works = true;
      REP(k, 0, 3) {
        fCopy[k] += rules[(i + j) % 7][k];
        if (fCopy[k] < 0) works = false;
      }
      if (works)
        best = max(best, j + 1);
      else
        break;
    }
  }
  cout << best + minWeeks * 7 << endl;
}
