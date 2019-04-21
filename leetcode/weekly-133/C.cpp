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
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    vi32 pre(A.size() + 1);
    REP(i, 0, A.size()) {
      pre[i + 1] = pre[i] + A[i];
    }
    i32 ret = 0;
    REP(i, 0, (A.size() - L + 1)) {
      REP(j, 0, (A.size() - M + 1)) {
        // non-overlap
        i32 iC = i, jC = j;
        i32 diff = L;  // Forgot swap the diff caused an extra attempt.
        if (iC > jC) {
          swap(iC, jC);
          diff = M;
        }
        if ((iC + diff - 1) >= jC) continue;

        i32 lV = pre[i + L] - pre[i];
        i32 mV = pre[j + M] - pre[j];
        ret = max(ret, lV + mV);
      }
    }
    return ret;
  }
};