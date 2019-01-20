#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

struct line {
  int id;
  int range[2];
};
line l[(i32)1e5];

int main() {
  i32 t; cin >> t;
  while (t--) {
    i32 n; cin >> n;
    REP(i, 0, n) {
      line newLine = {};
      cin >> newLine.range[0] >> newLine.range[1]; newLine.id = i;
      l[i] = newLine;
    }
    sort(l, l + n, [](line a, line b){
      if (a.range[0] != b.range[0]) {
        return a.range[0] < b.range[0];
      }
      return a.range[1] < b.range[1];
    });

    i32 g1Max = 0; i32 theOne = -1;
    REP(i, 0, n) {
      if (i < n - 1) {
        if ((i > 0) && (l[i].range[0] > g1Max) && (l[i].range[1] < l[i+1].range[1])) {
          theOne = i;
          break;
        }
      }
      if (i == (n-1)) {
        if ((l[i].range[0] > g1Max)) {
          theOne = i;
          break;
        }
      }

      if (g1Max < l[i].range[1])
        g1Max = l[i].range[1];
    }

    if (theOne == -1) {
      cout << -1 << "\n";
      continue;
    }

    // cout << (g2Max == 0 ?  2 : gMap[0]);
    cout << 1;
    REP(i, 1, n) cout << " " << (theOne == i ? 2 : 1);
    cout <<  "\n";
  }
}
