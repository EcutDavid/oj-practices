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

// Initially, created [101][3], changed to [2] after some reasoning.
i32 memo[101][2] = {};

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n; cin >> n;
  REP(i, 1, n + 1) {
    i32 num; cin >> num;
    i32 prevBest = min(memo[i - 1][0], memo[i - 1][1]);
    if (num & 1) {
      memo[i][0] = memo[i - 1][1];
    } else {
      memo[i][0] = prevBest + 1;
    }

    if (num & 2) {
      memo[i][1] = memo[i - 1][0];
    } else {
      memo[i][1] = prevBest + 1;
    }
  }
  cout << min(memo[n][0], memo[n][1]) << endl;
}
