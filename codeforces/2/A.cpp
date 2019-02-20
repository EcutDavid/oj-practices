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
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;

  vector<pair<string, i32>> a;
  map<string, i32> s;
  REP(i, 0, n) {
    string name;
    i32 score;
    cin >> name >> score;

    s[name] += score;
    a.push_back({name, score});
  }

  i32 bestScore = -1;  // "at the end of the game at least one player has a positive number of points."
  TR(s, it) {
    bestScore = max(bestScore, it->second);
  }

  set<string> candidates;
  TR(s, it) {
    if (it->second != bestScore) continue;
    candidates.insert(it->first);
  }
  if (candidates.size() == 1) {
    cout << *(candidates.begin()) << endl;
    return 0;
  }

  map<string, i32> acc;
  TR(a, it) {
    if (candidates.count(it->first) == 0) continue;

    acc[it->first] += it->second;
    if (acc[it->first] >= bestScore) {  // "than wins the one of them who scored at least m points first."
      cout << it->first << endl;
      return 0;
    }
  }
}
