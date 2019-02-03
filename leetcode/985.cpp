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
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    i32 evenSum = 0;
    vi32 ret;
    TR(A, it) {
      if (*it % 2 == 0) evenSum += *it;
    }

    TR(queries, it) {
      i32 index = (*it)[1];
      i32 prev = A[index], now = A[index] + (*it)[0];
      A[index] = now;

      if (prev % 2 == 0) {
        evenSum -= prev;
      }
      if (now % 2 == 0) {
        evenSum += now;
      }

      ret.PB(evenSum);
    }

    return ret;
  }
};
