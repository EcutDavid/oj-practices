// This solution only works for the small case.
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;

#define REP(i, a, b) for (auto i = a; i < b; i++)

i64 posToId(i64 y, i64 x) {
  return y * 1e5 + x;
}

unordered_map<char, pi32> dirs = {
    {'E', {0, 1}},
    {'W', {0, -1}},
    {'N', {-1, 0}},
    {'S', {1, 0}}};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 0, T) {
    i32 N, R, C, y, x;
    string code;
    cin >> N >> R >> C >> y >> x >> code;

    unordered_set<i64> visited;
    visited.insert(posToId(y, x));

    for (char c : code) {
      pi32 dir = dirs[c];
      while (visited.count(posToId(y, x))) {
        y += dir.first;
        x += dir.second;
      }
      visited.insert(posToId(y, x));
    }

    cout << "Case #" << t + 1 << ": " << y << " " << x << "\n";
  }
}
