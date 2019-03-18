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

const i32 wMin = 1, wMax = 500 * 50000;

class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int D) {
    i32 l = wMin, r = wMax, best = -1;
    while (l <= r) {
      i32 mid = (l + r) / 2, d = 1, cur = 0;
      TR(weights, it) {
        if (*it > mid) {
          d = D + 1;
          break;
        }

        if (*it + cur <= mid) {
          cur += *it;
          continue;
        }

        cur = *it;
        d++;
      }

      if (d <= D) {
        best = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return best;
  }
};