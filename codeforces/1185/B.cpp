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

  i32 n;
  cin >> n;
  REP(i, 0, n) {
    string o, s;
    cin >> o >> s;
    bool works = true;
    i32 p1 = 0;
    i32 p2 = 0;

    while (p1 != o.size()) {
      if (p2 == s.size()) {
        works = false;
        break;
      }
      if (o[p1] != s[p2]) break;

      if (p1 != (o.size() - 1) && o[p1] == o[p1 + 1]) {
        p1++;
        p2++;
        continue;
      }
      // Scan as far as possbile if p1 reach the end or the next char is not matching the cur.
      while (p2 != s.size() && s[p2] == o[p1]) {
        p2++;
      }
      p1++;
    }
    if (p2 != s.size()) {
      works = false;
    }
    cout << (works ? "YES" : "NO") << "\n";
  }
}
