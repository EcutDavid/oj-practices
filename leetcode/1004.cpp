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

class Solution {
 public:
  i32 longestOnes(vector<i32>& a, i32 k) {
    vi32 c(1, a[0] == 0 ? 1 : 0);
    REP(i, 1, a.size()) {
      c.push_back(c[i - 1]);
      c[i] += a[i] == 0 ? 1 : 0;
    }
    if (c[a.size() - 1] - k <= 0) return a.size();
    i32 best = 0;

    TR(c, it) {
      i32 goal = *it + k - (a[it - c.begin()] ? 0 : 1);
      auto end = upper_bound(it, c.end(), goal);
      best = max(best, i32(end - it));
    }
    return best;
  }
};