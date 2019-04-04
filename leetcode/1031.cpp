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

const i32 dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

class Solution {
 public:
  int numEnclaves(vector<vector<int>>& A) {
    if ((A.size() == 1) || (A[0].size() == 1)) return 0;

    i32 lCount = 0;
    REP(i, 0, A.size()) {
      REP(j, 0, A[0].size()) {
        lCount += A[i][j];
      }
    }

    queue<pi32> q;
    i32 bCount = 0;
    set<pi32> visited;
    REP(i, 0, A[0].size()) {
      if (A[0][i]) {
        pi32 pos = {0, i};
        q.push(pos);
        visited.insert(pos);
      }

      i32 lastY = A.size() - 1;
      if (A[lastY][i]) {
        pi32 pos = {lastY, i};
        q.push(pos);
        visited.insert(pos);
      }
      bCount += A[0][i] + A[lastY][i];
    }
    REP(i, 1, A.size() - 1) {
      if (A[i][0]) {
        pi32 pos = {i, 0};
        q.push(pos);
        visited.insert(pos);
      }

      i32 lastX = A[0].size() - 1;
      if (A[i][lastX]) {
        pi32 pos = {i, lastX};
        q.push(pos);
        visited.insert(pos);
      }
      bCount += A[i][0] + A[i][lastX];
    }

    while (!q.empty()) {
      pi32 pos = q.front();
      q.pop();

      for (auto dir : dirs) {
        i32 y = pos.first + dir[0], x = pos.second + dir[1];
        if (y < 0 || y >= A.size() || x < 0 || x >= A[0].size()) continue;
        if (!A[y][x] || visited.count({y, x})) continue;
        visited.insert({y, x});
        bCount++;
        q.push({y, x});
      }
    }

    return lCount - bCount;
  }
};
