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

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n, s, k;
  cin >> n >> s >> k;
  vector<i32> score(n + 1);
  REP(i, 0, n) {
    cin >> score[i + 1];
  }
  vector<i32> school(n + 1);
  REP(i, 0, n) {
    cin >> school[i + 1];
  }

  vector<i32> schoolRep(s + 1, -1);
  REP(i, 1, n + 1) {
    i32 rep = schoolRep[school[i]];
    if ((rep == -1) || (score[i] > score[rep])) {
      schoolRep[school[i]] = i;
    }
  }

  i32 total = 0;
  REP(i, 0, k) {
    i32 id;
    cin >> id;
    if (schoolRep[school[id]] != id) total++;
  }
  cout << total << endl;
}
