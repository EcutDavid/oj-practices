#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef int i32;
typedef vector<i32> vi32;
typedef pair<i32, i32> pi32;

#define REP(i, a, b) for (auto i = a; i < b; i++)
#define PRINT(x) cout << #x ": " << (x) << endl;

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n, m;
  cin >> n >> m;

  vi32 a(n), c(n);
  // Can also be done via priority queue.
  map<i32, set<i32>> food;
  REP(i, 0, n) {
    cin >> a[i];
  }
  REP(i, 0, n) {
    cin >> c[i];
    food[c[i]].insert(i);
  }

  REP(i, 0, m) {
    i64 cost = 0;
    i32 id, count;
    cin >> id >> count;
    id--;

    while (count && !food.empty()) {
      if (a[id] == 0) {
        id = *(food.begin()->second.begin());
      }
      i32 orderCount = min(count, a[id]);
      a[id] -= orderCount;
      count -= orderCount;
      cost += i64(orderCount) * c[id];
      if (a[id] > 0) continue;

      food[c[id]].erase(id);
      if (food[c[id]].empty()) food.erase(c[id]);
    }

    if (count) {
      cost = 0;
    }
    cout << cost << "\n";
  }
}
