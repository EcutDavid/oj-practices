#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef unsigned long long u64;
typedef unsigned int u32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

int h[(int)2e5];

int main() {
  i32 n, w, sum = 0;
  cin >> n >> w;
  REP(i, 0, n) cin >> h[i];
  REP(i, 0, w) sum += h[i];

  i32 sumMin = sum, bestIndex = 1;
  REP(i, 1, n - w + 1) {
    sum = sum - h[i - 1] + h[i - 1 + w];
    if (sumMin > sum) {
      sumMin = sum, bestIndex = i + 1;
    }
  }

  cout << bestIndex << endl;
}
