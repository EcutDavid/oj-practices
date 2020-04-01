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
  string target;
  cin >> n >> target;

  i32 bCount = 0, wCount = 0;
  for (char c : target) {
    bCount += c == 'B';
    wCount += c == 'W';
  }

  // If both of the count are odd, it's impossible to win.
  if ((bCount % 2) && (wCount % 2)) {
    cout << -1 << endl;
    return 0;
  }

  // If bCount is odd, our goal is to make every W become B.
  char finalC = bCount % 2 ? 'B' : 'W';
  i32 ret = 0;
  vi32 posArr;
  for (i32 i = 1; i < n; i++) {
    if (target[i - 1] != finalC) {
      posArr.push_back(i);
      target[i - 1] = target[i - 1] == 'W' ? 'B' : 'W';
      target[i] = target[i] == 'W' ? 'B' : 'W';
      ret++;
    }
  }

  cout << ret << endl;
  if (posArr.size() == 0) return 0;
  for (i32 i = 0; i < posArr.size(); i++) {
    cout << (i > 0 ? " " : "") << posArr[i];
  }
  cout << endl;
}
