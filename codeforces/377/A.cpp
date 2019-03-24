// The solution given by https://codeforces.com/blog/entry/10157 is much better,
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

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<string>& s, i32 y, i32 x, vector<vector<bool>>& v, vector<pi32>& o) {
  if (y < 0 || y >= s.size() || x < 0 || x >= s[0].size()) return;
  if (s[y][x] == '#' || v[y][x]) return;
  v[y][x] = true;
  REP(i, 0, 4) {
    dfs(s, y + dirs[i][0], x + dirs[i][1], v, o);
  }
  o.push_back({y, x});
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n);
  vector<vector<bool>> v;
  bool removed[n][m];

  REP(i, 0, n) {
    cin >> s[i];
    v.push_back(vector<bool>(m, false));
    REP(j, 0, m) {
      removed[i][j] = false;
    }
  }

  vector<pi32> o;
  REP(i, 0, n) {
    REP(j, 0, m) {
      dfs(s, i, j, v, o);
    }
  }
  REP(i, 0, k) {
    auto pos = o[i];
    // PRINT(pos.first);
    // PRINT(pos.second);
    // PRINT("=====");
    removed[pos.first][pos.second] = true;
  }
  REP(i, 0, n) {
    REP(j, 0, m) {
      cout << (removed[i][j] ? 'X' : s[i][j]);
    }
    cout << "\n";
  }
}
