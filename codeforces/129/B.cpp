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
	ios::sync_with_stdio(false); // Makes io faster, remove this line if C style scanf/printf needed.

  i32 n, m;
  cin >> n >> m;
  map<i32, unordered_set<i32>> adj = {};
  map<i32, i32> inDegree = {};
  REP(i, 0, n) adj[i] = unordered_set<i32>{};
  REP(i, 0, m) {
    i32 a, b; cin >> a >> b;
    inDegree[a]++; inDegree[b]++;
    adj[a].insert(b); adj[b].insert(a);
  }

  i32 counter = 0;
  while(true) {
    unordered_set<i32> g = {};
    REP(i, 1, n + 1) {
      if (inDegree[i] == 1) g.insert(i);
    }
    if (g.size() == 0) break;

    for (auto x : g) {
      inDegree[x]--;
      for (auto y : adj[x]) inDegree[y]--;
    }

    counter++;
  }
  cout << counter << endl;
}
