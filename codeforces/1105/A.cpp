// Brute force to find the best t
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

i32 cost(i32 a, i32 b) {
  if (b > a) swap(a, b);
  if (a == b) return 0;
  return (a - b - 1);
}

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n, a[1000]; cin >> n;
  REP(i, 0, n) cin >> a[i];

  i32 bestT = -1, bestRes = (i32)1e9;
  REP(i, 1, 101) {
    i32 res = 0;
    REP(j, 0, n) res += cost(a[j], i);

    if (res < bestRes) {
      bestRes = res; bestT = i;
    }
  }

  cout << bestT << " " << bestRes << endl;
}
