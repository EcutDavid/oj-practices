// 1. Can at most be the smallest number
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

int gcd(int a, int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n;
  cin >> n;
  unordered_map<i32, i32> m;
  REP(i, 0, n) {
    i32 num;
    cin >> num;
    m[num]++;
  }
  vi32 a;
  TR(m, it) {
    a.push_back(it->first);
  }
  if (m.size() == 1) {
    cout << a[0] << endl;
    return 0;
  }

  sort(all(a));
  i32 ret = 1;
  if (m[a[0]] == 1) {  // Can try remove the smallest one
    i32 gRet = a[1];
    REP(i, 2, a.size()) {
      gRet = gcd(gRet, a[i]);
    }
    ret = max(ret, gRet);
  }

  vi32 subRet;
  REP(i, 1, a.size()) {
    subRet.push_back(gcd(a[0], a[i]));
  }
  // Find the value that we can guard with
  // cout << subRet.size() << endl;
}
