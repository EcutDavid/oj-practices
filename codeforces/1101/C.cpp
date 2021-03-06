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
  ios::sync_with_stdio(false);

  i32 t; cin >> t;
  while (t--) {
    i32 n; cin >> n;
    REP(i, 0, n) {
      line newLine = {};
      cin >> newLine.range[0] >> newLine.range[1];
      newLine.id = i; l[i] = newLine;
    }
    sort(l, l + n, [](line a, line b){
      if (a.range[0] != b.range[0]) return a.range[0] < b.range[0];
      return a.range[1] < b.range[1];
    });

    unordered_set<i32> g1Set = {}; g1Set.insert(l[0].id);
    i32 rMax = l[0].range[1];
    REP(i, 1, n) {
      if (l[i].range[0] > rMax) break;
      g1Set.insert(l[i].id);
      if (l[i].range[1] > rMax) rMax = l[i].range[1];
    }
    if (g1Set.size() == n) {
      cout << -1 << endl; continue;
    }
    REP(i, 0, n) {
      cout << (i == 0 ? "" : " ") << (g1Set.count(i) == 1 ? 1 : 2);
    }
    cout << endl;
  }
}
