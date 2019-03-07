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

bool validate(bool b[3][3]) {
  unordered_map<i32, i32> hor, vert, dig1, dig2;
  if (b[1][1]) {
    if (b[0][0] && b[2][2]) return true;
    if (b[2][0] && b[0][2]) return true;
  }

  REP(i, 0, 3) {
    if (b[i][0] && b[i][1] && b[i][2]) return true;
    if (b[0][i] && b[1][i] && b[2][i]) return true;
  }
  return false;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;
  REP(i, 0, n) {
    string lines[3];
    REP(j, 0, 3) {
      cin >> lines[j];
    }
    bool x[3][3], o[3][3];
    i32 xCount = 0, oCount = 0;
    REP(j, 0, 3) {
      REP(k, 0, 3) {
        x[j][k] = lines[j][k] == 'X';
        xCount += x[j][k];
        o[j][k] = lines[j][k] == 'O';
        oCount += o[j][k];
      }
    }
    bool works = true;
    if ((xCount < oCount) || (xCount - oCount > 1))
      works = false;

    if (validate(x) && (xCount - oCount != 1))
      works = false;

    if (validate(o) && (xCount != oCount))
      works = false;

    cout << (works ? "yes\n" : "no\n");
  }
}
