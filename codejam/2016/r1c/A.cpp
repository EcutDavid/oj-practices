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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 t;
  cin >> t;
  REP(i, 1, t + 1) {
    cout << "Case #" << i << ":";

    i32 n;
    cin >> n;
    priority_queue<pair<i32, char> > q;
    REP(j, 0, n) {
      i32 c;
      cin >> c;
      q.push({c, 'A' + j});
    }

    while (q.size() > 2) {
      auto top = q.top();
      q.pop();
      top.first--;
      cout << " " << top.second;
      if (top.first) q.push(top);
    }

    while (!q.empty()) {
      auto a = q.top();
      q.pop();
      auto b = q.top();
      q.pop();
      a.first--;
      b.first--;
      cout << " " << a.second << b.second;
      if (a.first) {
        q.push(a);
        q.push(b);
      }
    }
    cout << "\n";
  }
}
