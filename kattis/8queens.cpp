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
  vector<pi32> q;
  REP(i, 0, 8) {
    string line;
    cin >> line;
    REP(j, 0, 8) {
      if (line[j] == '*') q.push_back(pi32{i, j});
    }
  }

  bool valid = q.size() == 8;

  if (valid) {
    unordered_set<i32> row, col, dia1, dia2;
    TR(q, it) {
      i32 x = it->second, y = it->first;
      if (row.count(y) || col.count(x) || dia1.count(x + y) || dia2.count(x - y)) {
        valid = false;
        break;
      }
      row.insert(y);
      col.insert(x);
      dia1.insert(x + y);
      dia2.insert(x - y);
    }
  }
  cout << (valid ? "valid" : "invalid") << endl;
}
