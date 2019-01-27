// Create a map for count characters, walk the string, each check should update the map.
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
  i32 n, k; string s;
  cin >> n >> k >> s;

  map<char, i32> cc, ans;
  REP(i, 0, s.size()) cc[s[i]] = 0;

  REP(i, 0, s.size()) {
    for (auto x : cc) {
      if(x.first == s[i]) continue;
      cc[x.first] = 0;
    }

    cc[s[i]]++;
    if (cc[s[i]] != k) continue;

    ans[s[i]]++; cc[s[i]] = 0;
  }

  i32 best = 0;
  for (auto x : ans) best = max(x.second, best);

  cout << best << endl;
}
