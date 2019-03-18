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
  int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<i32, i64> m;
    TR(time, it) {
      m[*it % 60]++;
    }
    i64 total = m[30] * (m[30] - 1) / 2 + m[0] * (m[0] - 1) / 2;
    REP(i, 1, 30) {
      total += m[i] * m[60 - i];
    }
    return i32(total);
  }
};