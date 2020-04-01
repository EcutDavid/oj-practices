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

set<i32> genPrimeSet(int n) {
  set<i32> ret;
  vector<bool> isP(n + 1, true);
  isP[0] = false;
  isP[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!isP[i]) continue;
    ret.insert(i);
    for (int j = i * 2; j <= n; j += i) {
      isP[j] = false;
    }
  }

  return ret;
}
// All the primes are interesting
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  auto ps = genPrimeSet(1e6);

  i32 T;
  cin >> T;
  REP(t, 1, T + 1) {
    cout << "Case #" << t << ": ";
    i32 l, r;
    cin >> l >> r;
    if (r > 1e6) {
      cout << "don't know, sorry\n";
      continue;
    }

    i32 count = 0;

    REP(i, l, r + 1) {
      if (ps.count(i)) {
        count++;
        continue;
      }

      int num = i;
      int p2 = 0;
      while (num % 2 == 0) {
        p2++;
        num /= 2;
      }
      if (p2 == 1) {
        count++;
        continue;
      }
      if (p2 > 3) {
        continue;
      }
      int otherP = 0;
      for (auto d : ps) {
        if (d > num) break;
        while (num % d == 0) {
          otherP++;
          num /= d;

          if ((p2 == 0 && otherP > 1) || (p2 == 2 && otherP > 1) || (p2 == 3 && otherP > 0)) {
            break;
          }
        }
      }
      // Case 1: p2 == 0, if otherP <= 1, it will be in range
      // Case 2: p2 == 1, both side would be equal
      // Case 3: p2 == 2, 2a: otherP == 0, { 1 } VS { 2, 4 } will be in range
      //                  2b: otherP == 1, { 1, k } VS { 2, 4, 2 * k, 4 * k } will be in range
      //                  2c: otherP > 1,  { 1, k, k^x, ... } VS { 2, 4, 2 * k, 4 * k, ... }, will not be in range
      // Case 4: p2 == 3, otherP > 0 will not be in range
      // Case 5: p2 > 3, will not be in range, covered ealier.
      if ((p2 == 0 && otherP > 1) || (p2 == 2 && otherP > 1) || (p2 == 3 && otherP > 0)) {
        continue;
      }
      count++;
    }

    cout << count << "\n";
  }
}
