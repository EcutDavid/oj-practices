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
  set<i32> s;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    s.insert(num);
  }
  if (s.size() > 3 || s.size() == 1) {
    cout << (s.size() == 1 ? 0 : -1) << endl;
    return 0;
  }

  i32 start = *(s.begin());
  if (s.size() == 2) {
    i32 end = *(++s.begin()), range = end - start;
    if (range % 2 == 0) {
      cout << range / 2 << endl;
    } else {
      cout << range << endl;
    }
    return 0;
  }

  auto it = s.end();
  i32 end = *(--it);
  i32 mid = *(--it);
  if ((end - mid) != (mid - start)) {
    cout << -1 << endl;
    return 0;
  }
  cout << end - mid << endl;
}
