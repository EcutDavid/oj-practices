// Calculate the adjlist is not faster enough as there are 2 * 10 ^ 5 vertices.
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

i64 a[(int)2e5];

i32 main() {
  i32 n, m;
  cin >> n >> m;
  REP(i, 0, n)
      cin >> a[i];
  i64 adj[n + 1][n + 1];
  REP(i, 1, n + 1) {
    REP(j, 1, n + 1) {
      if (i == j) continue;
      adj[i][j] = a[i - 1] + a[j - 1];
    }
  }
  REP(i, 0, m) {
    i64 v1, v2, w;
    cin >> v1 >> v2 >> w;
    if (adj[v1][v2] > w) {
      adj[v1][v2] = w;
      adj[v2][v1] = w;
    }
  }
  priority_queue<pair<i64, i32>> q = {};
  map<int, bool> processed = {};
  i64 sum = 0;
  q.push(pair<i64, i32>{0, 1});
  while (q.size()) {
    auto item = q.top();
    q.pop();
    if (processed[item.second]) continue;
    cout << "process" << item.second << "  " << item.first << endl;
    processed[item.second] = true;
    sum += -item.first;

    REP(i, 1, n + 1) {
      if (i == item.second) continue;
      q.push(pair<i64, i32>{-adj[item.second][i], i});
    }
  }

  cout << sum << endl;
}
