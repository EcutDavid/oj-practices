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

// unordered_map<i32, i32> findPrime(i32 a) {
//   unordered_map<i32, i32> ret;

//   REP(i, 2, 101) {
//     while (a % i == 0) {
//       ret[i]++;
//       a /= i;
//     }
//   }
//   if (a > 1) ret[a]++;
//   return ret;
// }

// i32 main() {
//   ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
//   unordered_map<i32, i32> prime[10001];
//   REP(i, 1, 10001) {
//     prime[i] = findPrime(i);
//   }

//   i32 a, b, c;
//   cin >> a >> b >> c;
//   unordered_map<i32, i32> m;

//   i64 total = 0;
//   REP(i, 1, a + 1) {
//     REP(j, 1, b + 1) {
//       REP(k, 1, c + 1) {
//         vi32 b = {i, j, k};
//         sort(all(b));
//         i32 key = i32(1e4) * b[0] + i32(1e2) * b[1] + b[2];

//         if (m.find(key) == m.end()) {
//           unordered_map<i32, i32> x = prime[i * j], &y = prime[k];
//           TR(y, it) {
//             x[it->first] += it->second;
//           }
//           i32 divSum = 1;
//           TR(x, it) {
//             divSum *= it->second + 1;
//           }
//           m[key] = divSum;
//         }

//         total = (total + m[key]) % 1073741824;
//       }
//     }
//   }

//   cout << total << endl;
// }

i32 m[i32(1e6) + 1] = {};

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 a, b, c;
  cin >> a >> b >> c;
  i32 target = a * b * c;
  REP(i, 1, target + 1) {
    REP(j, 1, target / i + 1) {
      m[i * j]++;
    }
  }

  i64 total = 0;
  REP(i, 1, a + 1) {
    REP(j, 1, b + 1) {
      REP(k, 1, c + 1) {
        total = (total + m[i * j * k]) % 1073741824;
      }
    }
  }

  cout << total << endl;
}
