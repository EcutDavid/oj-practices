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

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    int w = grid[0].size();
    int h = grid.size();
    queue<vector<int>> q;
    q.push({r0, c0});
    set<vector<int>> visited;
    visited.insert({r0, c0});

    while (q.size()) {
      vector<int> task = q.front();
      q.pop();

      bool needColor = false;
      for (auto dir : dirs) {
        int newY = dir[0] + task[0];
        int newX = dir[1] + task[1];
        if (newY < 0 || newY >= h || newX < 0 || newX >= w) continue;
        if (visited.count({newY, newX})) continue;
        if (grid[newY][newX] != grid[task[0]][task[1]]) needColor = true;

        if (grid[newY][newX] == grid[task[0]][task[1]]) {
          q.push({newY, newX});
          visited.insert({newY, newX});
        }
      }

      if (needColor || task[0] == 0 || task[1] == 0 || task[0] == (h - 1) || task[1] == (w - 1)) {
        grid[task[0]][task[1]] = color;
      }
    }
    return grid;
  }
};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
}
