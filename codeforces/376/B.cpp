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

#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front

i32 in[101], out[101];
i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, m; cin >> n >> m;
  while (m--) {
    i32 a, b, c; cin >> a >> b >> c;
    in[b] += c; out[a] += c;
  }

  i32 sumMin = 0;
  REP(i, 1, n + 1) sumMin += in[i] - min(in[i], out[i]);

  cout << sumMin << endl;
}
