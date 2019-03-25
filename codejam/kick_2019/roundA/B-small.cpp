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

i32 posToKey(pi32 p) {
  return p.first * 300 + p.second;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 T;
  cin >> T;
  REP(t, 0, T) {
    i32 r, c;
    cin >> r >> c;
    vector<pi32> o(r * c), h(r * c);
    i32 oCount = 0, hCount = 0;
    REP(i, 0, r) {
      string row;
      cin >> row;
      REP(j, 0, c) {
        pi32 pos = {i, j};
        if (row[j] == '1')
          o[oCount++] = pos;
        else
          h[hCount++] = pos;
      }
    }
    if (hCount < 2) {
      cout << "Case #" << t + 1 << ": " << 0 << "\n";
      continue;
    }

    unordered_map<i32, i32> m;
    REP(k, 0, hCount) {
      i32 bestDistance = i32(1e9);
      REP(j, 0, oCount) {
        i32 distance = abs(o[j].first - h[k].first) + abs(o[j].second - h[k].second);
        bestDistance = min(bestDistance, distance);
      }
      m[posToKey(h[k])] = bestDistance;
    }

    i32 ans = i32(1e9);
    REP(i, 0, hCount) {
      auto mCopy = m;
      mCopy[posToKey(h[i])] = 0;
      REP(j, 0, hCount) {
        if (j == i) continue;
        i32 distance = abs(h[i].first - h[j].first) + abs(h[i].second - h[j].second);
        i32 key = posToKey(h[j]);
        mCopy[key] = min(mCopy[key], distance);
      }
      i32 ret = 0;
      TR(mCopy, it) {
        ret = max(ret, it->second);
      }
      ans = min(ret, ans);
    }

    cout << "Case #" << t + 1 << ": " << ans << "\n";
  }
}
