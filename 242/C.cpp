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

#define REP(i, a, b) for (i32 i = a; i < b; i++)
#define PB push_back
#define PF push_front

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 sx, sy, fx, fy, n; cin >> sx >> sy >> fx >> fy >> n;
  set<pi32> p;
  REP(i, 0, n) {
    i32 x, y1, y2; cin >> x >> y1 >> y2;
    REP(j, y1, y2 + 1) p.insert({x, j});
  }

  queue<pi32> q; q.push({ sx, sy });
  set<pi32> v; v.insert({ sx, sy });
  map<pi32, i32> d; d[{sx, sy}] = 0;
  while(q.size()) {
    pi32 job = q.front(); q.pop();

    if (job == pi32{ fx, fy }) {
      cout << d[job] << endl;
      return 0;
    }

    REP(i, -1, 2) {
      REP(j, -1, 2) {
        if ((i == 0) && (j == 0)) continue;
        pi32 newPos = pi32 { job.first + i, job.second + j };
        if (!p.count(newPos) || v.count(newPos)) continue;

        v.insert(newPos); d[newPos] = d[job] + 1; q.push(newPos);
      }
    }
  }
  cout << -1 << endl;
}
