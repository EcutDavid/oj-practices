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

vi32 addDigits(vi32 a, vi32 b) {
  if (a.size() < b.size()) swap(a, b);
  vi32 answer = a; i32 acc = 0;

  REP(i, 0, a.size()) {
    int addRes = a[i] + (b.size() > i ? b[i] : 0) + acc;
    answer[i] = addRes % 10; acc = addRes / 10;
  }
  if (acc > 0) answer.PB(acc);

  while ((answer.size() > 0) && (answer.back() == 0)) answer.pop_back();
  return answer;
}

i32 main() {
  i32 t; cin >> t;
  while (t--) {
    vi32 a = {}, b = {}; string rawA, rawB;
    cin >> rawA >> rawB;
    REP(i, 0, rawA.size()) a.PB(rawA[i] - '0');
    REP(i, 0, rawB.size()) b.PB(rawB[i] - '0');
    vi32 res = addDigits(a, b);

    if (res.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    i32 leadNonZeroIndex = -1;
    REP(i, 0, res.size()) {
      if (res[i] != 0) {
        leadNonZeroIndex = i; break;
      }
    }
    REP(i, leadNonZeroIndex, res.size()) cout << res[i];
    cout << endl;
  }
}
