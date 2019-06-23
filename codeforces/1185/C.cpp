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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m;
  cin >> n >> m;

  priority_queue<int> pq;
  i32 totalT = 0;
  REP(i, 0, n) {
    i32 c;
    cin >> c;

    auto pqCopy = pq;
    pq.push(c);
    totalT += c;
    i32 t = totalT;
    i32 ret = 0;
    while (t > m) {
      t -= pqCopy.top();
      ret++;
      pqCopy.pop();
    }

    cout << (i > 0 ? " " : "") << ret;
  }
  cout << endl;
}
