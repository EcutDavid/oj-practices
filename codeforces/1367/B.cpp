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
#define TR(c, it) for (auto (it) = (c).begin(); (it) != (c).end(); (it)++)

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.

  i32 n;
  cin >> n;

  REP (i, 0, n) {
    i32 c;
    cin >> c;
    vi32 wrongCount(2, 0);

    REP (j, 0, c) {
      i32 num;
      cin >> num;
      if (j % 2 == 1 && num % 2 == 0) {
        wrongCount[1]++;
      }

      if (j % 2 == 0 && num % 2 == 1) {
        wrongCount[0]++;
      }
    }
    if (wrongCount[0] != wrongCount[1]) {
      cout << -1;
    } else {
      cout << wrongCount[0];
    }
    cout << "\n";
  }
}
