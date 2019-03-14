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

i32 dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m;
  cin >> n >> m;

  vector<vector<bool>> a, v;
  REP(i, 0, n) {
    a.push_back(vector<bool>());
    v.push_back(vector<bool>());
    REP(j, 0, m) {
      char c;
      cin >> c;
      a[i].push_back(c == '.');
      v[i].push_back(false);
    }
  }

  i32 sum = 0;
  REP(i, 0, n) {
    REP(j, 0, m) {
      if (v[i][j] || !a[i][j]) continue;
      sum++;
      v[i][j] = true;

      queue<pi32> q;
      q.push({i, j});
      while (!q.empty()) {
        auto task = q.front();
        q.pop();

        REP(k, 0, 4) {
          i32 y = task.first + dir[k][0], x = task.second + dir[k][1];
          if (y < 0 || x < 0 || y >= n || x >= m || v[y][x] || !a[y][x]) continue;
          q.push({y, x});
          v[y][x] = true;
        }
      }
    }
  }

  cout << sum << endl;
}
