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

map<i32, i32> get_factors(i32 n) {
  map<i32, i32> res = {};
  i32 s = (i32)sqrt(n);
  REP(i, 2, s + 1) {
    while (n % i == 0) {
      n /= i; res[i]++;
    }
  }
  // Using = instead of > here cost me 5 mins.
  if (n > 1) res[n]++;
  return res;
}

i32 main() {
	ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 a, b; cin >> a >> b;
  map<i32, i32> af = get_factors(a), bf =get_factors(b);

  unordered_set<i32> keySet = {};
  for (auto x : af) keySet.insert(x.first);
  for (auto x : bf) keySet.insert(x.first);

  for (auto x : keySet) {
    if ((x == 2) || (x == 3) || (x == 5)) continue;
    if ((af[x] == 0) || (bf[x] == 0)) {
      cout << -1 << endl;
      return 0;
    }
  }

  i32 sum = 0;
  for (auto x : {2, 3, 5}) {
    sum += max(af[x], bf[x]) - min(af[x], bf[x]);
  }
  cout << sum << endl;
}
