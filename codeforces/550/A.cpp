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
  string s;
  cin >> s;

  unordered_set<i32> ab;
  REP(i, 0, s.size() - 1) {
    if ((s[i] == 'A') && (s[i + 1] == 'B')) ab.insert(i);
  }

  REP(i, 0, s.size() - 1) {
    i32 index = s.size() - i - 2;
    // Easy to get this part wrong if not think carefully.
    if ((s[index] != 'B') || (s[index + 1] != 'A')) continue;

    if (ab.size() - ab.count(index - 1) - ab.count(index + 1)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}
