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
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  map<i32, i32> memo = {};
  // Simple brute force.
  REP(i, 5, 101) {
    bool p[100] = {};
    REP(j, 1, i + 1) {
      REP(k, 1, i + 1) {
        if (k % j == 0) p[k-1] = !p[k-1];
      }
    }

    i32 sum = 0;
    REP(j, 0, i) {
      if (p[j]) sum++;
    }
    memo[i] = sum;
  }

  i32 n; cin >> n;
  while(n--) {
    i32 a; cin >> a;
    cout << memo[a] << endl;
  }
}
