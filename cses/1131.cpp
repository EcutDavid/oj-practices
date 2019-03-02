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

// Using array for adj whenever we can as it's faster than unordered_map.
vi32 adj[i32(5e5) + 1] = {};

pi32 dfs(i32 cur, i32 distance, i32 parent) {
  pi32 best = {distance, cur};
  TR(adj[cur], it) {
    if (*it == parent) continue;
    best = max(best, dfs(*it, distance + 1, cur));
  }
  return best;
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n;
  cin >> n;
  REP(i, 0, n - 1) {
    i32 a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  i32 dis, node;
  tie(dis, node) = dfs(1, 0, -1);
  tie(dis, node) = dfs(node, 0, -1);

  cout << dis << endl;
}
