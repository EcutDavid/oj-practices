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
  i32 n;
  cin >> n; i32 p[n];
  REP(i, 0, n) cin >> p[i];
  i32 descBegin = -1, descEnd = -1;
  REP(i, 1, n) {
    if (p[i] < p[i - 1]) {
      if (descEnd != -1) { cout << "no" << endl; return 0; }
      if (descBegin != -1) continue;
      descBegin = i - 1;
    } else if (descBegin != -1) {
      if (descEnd != -1) continue;
      descEnd = i - 1;
    }
  }

  if (descBegin != -1) {
    if (descEnd == -1) descEnd = n - 1;
    bool failedAtEnd = (descBegin != 0) && (p[descEnd] < p[descBegin - 1]);
    bool failedAtBegin = (descEnd != (n - 1)) && (p[descBegin] > p[descEnd + 1]);
    if (failedAtBegin || failedAtEnd) { cout << "no" << endl; return 0; }
  }

  if (descBegin == -1) descBegin = descEnd = 0;
  cout << "yes\n" << descBegin + 1 << " " << descEnd + 1 << endl;
}
