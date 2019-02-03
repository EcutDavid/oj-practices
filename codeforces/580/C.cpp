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
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

bool c[(i32)2e5 + 1];
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, cMax;
  cin >> n >> cMax;

  REP(i, 1, n + 1) {
    i32 key;
    cin >> key;
    c[i] = key == 1;
  }

  unordered_map<i32, unordered_set<i32> > adj;
  REP(i, 0, n - 1) {
    i32 x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }

  queue<i32> q;
  q.push(1);
  unordered_map<i32, i32> cats = {{1, c[1] ? 1 : 0}};
  unordered_set<i32> v = {1};

  i32 total = 0;
  while (!q.empty()) {
    i32 cur = q.front();
    q.pop();
    if (cats[cur] > cMax) continue;

    bool isLeaf = true;
    for (auto x : adj[cur]) {
      if (v.count(x)) continue;

      v.insert(x);
      // "consecutive vertices"
      cats[x] = c[x] ? (cats[cur] + 1) : 0;
      q.push(x);
      isLeaf = false;
    }

    if (isLeaf) total++;
  }

  cout << total << endl;
}
