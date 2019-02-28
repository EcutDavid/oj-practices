// Edge case 1: no one can speak any language.
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
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

map<i32, set<i32>> lanToP;
map<i32, set<i32>> pToLan;
vector<bool> visited(100, false);

i32 n, m;

void visit(i32 p) {
  visited[p] = true;

  TR(pToLan[p], lan) {
    TR(lanToP[*lan], d) {
      if (visited[*d]) continue;
      visit(*d);
    }
  }
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  cin >> n >> m;
  bool cannotSpeakAtAll = true;
  REP(i, 0, n) {
    i32 lan;
    cin >> lan;
    if (lan) cannotSpeakAtAll = false;
    set<i32> l;
    REP(j, 0, lan) {
      i32 d;
      cin >> d;
      l.insert(d);
      lanToP[d].insert(i);
      pToLan[i].insert(d);
    }
  }

  if (cannotSpeakAtAll) {
    cout << n << endl;
    return 0;
  }

  i32 total = -1;
  REP(i, 0, n) {
    if (visited[i]) continue;
    total++;
    visit(i);
  }
  cout << total << endl;
}
