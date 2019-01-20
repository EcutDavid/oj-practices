#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef unsigned long long u64;
typedef unsigned int u32;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define PB push_back

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  i32 n = 0, nums[50];
  while(cin >> n) {
    if (n == 0) break;

    REP(i, 0, n) cin >> nums[i];

    i32 total = (n - 1) * n / 2, gcdOneCount = 0;
    REP(i, 0, n-1) {
      REP(j, i + 1, n) {
        if (gcd(nums[i], nums[j]) == 1) gcdOneCount++;
      }
    }
    if (gcdOneCount == 0) {
      cout << "No estimate for this data set.\n";
    } else {
      f64 pi = sqrt(6.0 * (f64)total / (f64)gcdOneCount);
      printf("%.6f\n", pi);
    }
  }
}
